// -*- coding: utf-8 -*-
// Copyright (C) 2012 MUJIN Inc. <rosen.diankov@mujin.co.jp>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
/** \file mujincontrollerclient.h
    \brief  Defines the public headers of the MUJIN Controller Client
 */
#ifndef MUJINCLIENT_H
#define MUJINCLIENT_H

#ifndef MUJINCLIENT_DISABLE_ASSERT_HANDLER
#define BOOST_ENABLE_ASSERT_HANDLER
#endif

#define BOOST_FILESYSTEM_VERSION 3 // use boost filesystem v3

#ifdef _MSC_VER

#pragma warning(disable:4251) // needs to have dll-interface to be used by clients of class
#pragma warning(disable:4190) // C-linkage specified, but returns UDT 'boost::shared_ptr<T>' which is incompatible with C
#pragma warning(disable:4819) //The file contains a character that cannot be represented in the current code page (932). Save the file in Unicode format to prevent data loss using native typeof

#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__ __FUNCDNAME__
#endif

#else
#endif

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <exception>

#include <iomanip>
#include <fstream>
#include <sstream>

#include <boost/version.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/format.hpp>

namespace mujinclient {

#include <mujincontrollerclient/config.h>

enum MujinErrorCode {
    MEC_Failed=0,
    MEC_InvalidArguments=1, ///< passed in input arguments are not valid
    MEC_EnvironmentNotLocked=2,
    MEC_CommandNotSupported=3, ///< string command could not be parsed or is not supported
    MEC_Assert=4,
    MEC_NotInitialized=9, ///< when object is used without it getting fully initialized
    MEC_InvalidState=10, ///< the state of the object is not consistent with its parameters, or cannot be used. This is usually due to a programming error where a vector is not the correct length, etc.
    MEC_Timeout=11, ///< process timed out
};

inline const char* GetErrorCodeString(MujinErrorCode error)
{
    switch(error) {
    case MEC_Failed: return "Failed";
    case MEC_InvalidArguments: return "InvalidArguments";
    case MEC_EnvironmentNotLocked: return "EnvironmentNotLocked";
    case MEC_CommandNotSupported: return "CommandNotSupported";
    case MEC_Assert: return "Assert";
    case MEC_NotInitialized: return "NotInitialized";
    case MEC_InvalidState: return "InvalidState";
    case MEC_Timeout: return "Timeout";
    }
    // should throw an exception?
    return "";
}


/// \brief Exception that all Mujin internal methods throw; the error codes are held in \ref MujinErrorCode.
class MUJINCLIENT_API mujin_exception : public std::exception
{
public:
    mujin_exception() : std::exception(), _s("unknown exception"), _error(MEC_Failed) {
    }
    mujin_exception(const std::string& s, MujinErrorCode error=MEC_Failed) : std::exception() {
        _error = error;
        _s = "mujin (";
        _s += GetErrorCodeString(_error);
        _s += "): ";
        _s += s;
    }
    virtual ~mujin_exception() throw() {
    }
    char const* what() const throw() {
        return _s.c_str();
    }
    const std::string& message() const {
        return _s;
    }
    MujinErrorCode GetCode() const {
        return _error;
    }
private:
    std::string _s;
    MujinErrorCode _error;
};

class ControllerClient;
class SceneResource;
class TaskResource;
class OptimizationResource;
class PlanningResultResource;

typedef boost::shared_ptr<ControllerClient> ControllerClientPtr;
typedef boost::weak_ptr<ControllerClient> ControllerClientWeakPtr;
typedef boost::shared_ptr<SceneResource> SceneResourcePtr;
typedef boost::weak_ptr<SceneResource> SceneResourceWeakPtr;
typedef boost::shared_ptr<TaskResource> TaskResourcePtr;
typedef boost::weak_ptr<TaskResource> TaskResourceWeakPtr;
typedef boost::shared_ptr<OptimizationResource> OptimizationResourcePtr;
typedef boost::weak_ptr<OptimizationResource> OptimizationResourceWeakPtr;
typedef boost::shared_ptr<PlanningResultResource> PlanningResultResourcePtr;
typedef boost::weak_ptr<PlanningResultResource> PlanningResultResourceWeakPtr;
typedef double Real;

struct JobStatus
{
    JobStatus() : code(0) {
    }
    int code; ///< if 3, succeeded
    std::string message;
};

/// \brief an affine transform
struct Transform
{
    Transform() {
        quat[0] = 1; quat[1] = 0; quat[2] = 0; quat[3] = 0;
        translation[0] = 0; translation[1] = 0; translation[2] = 0;
    }
    Real quat[4]; ///< quaternion [cos(ang/2), axis*sin(ang/2)]
    Real translation[3]; ///< translation x,y,z
};

/// \brief Creates on MUJIN Controller instance.
///
/// Only one call can be made at a time. In order to make multiple calls simultaneously, create another instance.
class MUJINCLIENT_API ControllerClient
{
public:
    virtual ~ControllerClient() {
    }

    /** \brief Returns a list of filenames in the user system of a particular type

        \param scenetype the type of scene possible values are:
        - mujincollada
        - wincaps
        - rttoolbox
        - cecvirfitxml
        - stl
        - x
        - vrml
        - stl
     */
    virtual void GetSceneFilenames(const std::string& scenetype, std::vector<std::string>& scenefilenames) = 0;

    /// \brief gets a list of all the scene primary keys currently available to the user
    virtual void GetScenePrimaryKeys(std::vector<std::string>& scenekeys) = 0;

    //virtual SceneResourcePtr GetScene(const std::string& pk);
};

class MUJINCLIENT_API WebResource
{
public:
    WebResource(ControllerClientPtr controller, const std::string& resourcename, const std::string& pk);
    virtual ~WebResource() {
    }

    inline ControllerClientPtr GetController() const {
        return __controller;
    }
    inline const std::string& GetResourceName() const {
        return __resourcename;
    }
    inline const std::string& GetPrimaryKey() const {
        return __pk;
    }

    /// \brief gets an attribute of this web resource
    std::string Get(const std::string& field);

private:
    ControllerClientPtr __controller;
    std::string __resourcename, __pk;
};

class MUJINCLIENT_API SceneResource : public WebResource
{
public:
    SceneResource(ControllerClientPtr controller, const std::string& pk);
    virtual ~SceneResource() {
    }

    /// \brief Gets or creates the a task part of the scene
    ///
    /// \param taskname the name of the task to search for or create
    virtual TaskResourcePtr GetOrCreateTaskFromName(const std::string& taskname);

    /// \brief gets a list of all the scene primary keys currently available to the user
    //virtual void GetTaskPrimaryKeys(std::vector<std::string>& task) = 0;
};

class MUJINCLIENT_API TaskResource : public WebResource
{
public:
    TaskResource(ControllerClientPtr controller, const std::string& pk);
    virtual ~TaskResource() {
    }

    /// \brief execute the task
    virtual void Execute();

    /// \brief get the run-time status of the executed task
    virtual JobStatus GetRunTimeStatus();

    /// \brief Gets or creates the a optimization part of the scene
    ///
    /// \param optimizationname the name of the optimization to search for or create
    virtual OptimizationResourcePtr GetOrCreateOptimizationFromName(const std::string& optimizationname);

    /// \brief gets the result of the task execution. If no result has been computed yet, will return a NULL pointer.
    virtual PlanningResultResourcePtr GetResult();
};

class MUJINCLIENT_API OptimizationResource : public WebResource
{
public:
    OptimizationResource(ControllerClientPtr controller, const std::string& pk);
    virtual ~OptimizationResource() {
    }

    /// \brief execute the optimization
    virtual void Execute();

    /// \brief get the run-time status of the executed optimization
    virtual JobStatus GetRunTimeStatus();

    /// \brief gets the fastest results of the optimization execution.
    ///
    /// \param fastestnum The number of results to get starting with the fastest task_time. If 0, will return ALL results.
    virtual void GetResults(int fastestnum, std::vector<PlanningResultResourcePtr>& results);
};

class MUJINCLIENT_API PlanningResultResource : public WebResource
{
public:
    PlanningResultResource(ControllerClientPtr controller, const std::string& pk);
    virtual ~PlanningResultResource() {
    }

    /// \brief Get all the transforms the results are storing. Depending on the optimization, can be more than just the robot
    virtual void GetTransforms(std::map<std::string, Transform>& transforms);
};


/// \brief creates the controller with an account.
///
/// \param usernamepassword user:password
/// <b>This function is not thread safe.</b> You must not call it when any other thread in the program (i.e. a thread sharing the same memory) is running.
MUJINCLIENT_API ControllerClientPtr CreateControllerClient(const std::string& usernamepassword);

/// \brief called at the very end of an application to safely destroy all controller client resources
MUJINCLIENT_API void ControllerClientDestroy();

/// \brief Compute a 3x4 matrix from a Transform
MUJINCLIENT_API void ComputeMatrixFromTransform(Real matrix[12], const Transform &transform);

/** \brief Compute Euler angles in ZXY order (T = Z*X*Y) from a 3x4 matrix

    Rx = Matrix(3,3,[1,0,0,0,cos(x),-sin(x),0,sin(x),cos(x)])
    Ry = Matrix(3,3,[cos(y),0,sin(y),0,1,0,-sin(y),0,cos(y)])
    Rz = Matrix(3,3,[cos(z),-sin(z),0,sin(z),cos(z),0,0,0,1])
    Rz*Rx*Ry

    [-sin(x)*sin(y)*sin(z) + cos(y)*cos(z), -sin(z)*cos(x),  sin(x)*sin(z)*cos(y) + sin(y)*cos(z)]
    [ sin(x)*sin(y)*cos(z) + sin(z)*cos(y),  cos(x)*cos(z), -sin(x)*cos(y)*cos(z) + sin(y)*sin(z)]
    [                       -sin(y)*cos(x),         sin(x),                         cos(x)*cos(y)]

 */
MUJINCLIENT_API void ComputeZXYFromMatrix(Real ZXY[3], const Real matrix[12]);

MUJINCLIENT_API void ComputeZXYFromTransform(Real ZXY[3], const Transform &transform);

}

#if !defined(MUJINCLIENT_DISABLE_ASSERT_HANDLER) && defined(BOOST_ENABLE_ASSERT_HANDLER)
/// Modifications controlling %boost library behavior.
namespace boost
{
inline void assertion_failed(char const * expr, char const * function, char const * file, long line)
{
    throw mujinclient::mujin_exception(boost::str(boost::format("[%s:%d] -> %s, expr: %s")%file%line%function%expr),mujinclient::MEC_Assert);
}

#if BOOST_VERSION>104600
inline void assertion_failed_msg(char const * expr, char const * msg, char const * function, char const * file, long line)
{
    throw mujinclient::mujin_exception(boost::str(boost::format("[%s:%d] -> %s, expr: %s, msg: %s")%file%line%function%expr%msg),mujinclient::MEC_Assert);
}
#endif

}
#endif

BOOST_STATIC_ASSERT(MUJINCLIENT_VERSION_MAJOR>=0&&MUJINCLIENT_VERSION_MAJOR<=255);
BOOST_STATIC_ASSERT(MUJINCLIENT_VERSION_MINOR>=0&&MUJINCLIENT_VERSION_MINOR<=255);
BOOST_STATIC_ASSERT(MUJINCLIENT_VERSION_PATCH>=0&&MUJINCLIENT_VERSION_PATCH<=255);

#endif
