// -*- coding: utf-8 -*-
// Copyright (C) 2017 MUJIN Inc.

/** \file controllerclientimpl.h
    \brief  Private header file implementing the ControllerClient interface
 */

#ifndef MUJIN_CONTROLLERCLIENT_IMPL_H
#define MUJIN_CONTROLLERCLIENT_IMPL_H

#include <mujincontrollerclient/mujincontrollerclient.h>

#include <boost/enable_shared_from_this.hpp>

namespace mujinclient {

class ControllerClientMock : public ControllerClient, public boost::enable_shared_from_this<ControllerClientMock>
{
public:
    ControllerClientMock(const std::string& usernamepassword, const std::string& baseuri, const std::string& proxyserverport, const std::string& proxyuserpw, int options, double timeout);
    virtual ~ControllerClientMock();

    // controller client interface

    void SetCharacterEncoding(const std::string& newencoding);
    const std::string& GetUserName() const;
    void SetLanguage(const std::string& language);
    void SetProxy(const std::string& serverport, const std::string& userpw);
    void RestartServer(double timeout);
    void Upgrade(const std::vector<unsigned char>& vdata);
    std::string GetVersion();
    void CancelAllJobs();
    void GetRunTimeStatuses(std::vector<JobStatus>& statuses, int options);
    void GetScenePrimaryKeys(std::vector<std::string>& scenekeys);
    SceneResourcePtr RegisterScene_UTF8(const std::string& uri, const std::string& scenetype);
    SceneResourcePtr RegisterScene_UTF16(const std::wstring& uri, const std::string& scenetype);
    SceneResourcePtr ImportSceneToCOLLADA_UTF8(const std::string& importuri, const std::string& importformat, const std::string& newuri, bool overwrite=false);
    SceneResourcePtr ImportSceneToCOLLADA_UTF16(const std::wstring& importuri, const std::string& importformat, const std::wstring& newuri, bool overwrite=false);
    void SyncUpload_UTF8(const std::string& sourcefilename, const std::string& destinationdir, const std::string& scenetype);
    void SyncUpload_UTF16(const std::wstring& sourcefilename_utf16, const std::wstring& destinationdir_utf16, const std::string& scenetype);
    void UploadFileToController_UTF8(const std::string& filename, const std::string& desturi);
    void UploadFileToController_UTF16(const std::wstring& filename, const std::wstring& desturi);
    void UploadDataToController_UTF8(const std::vector<unsigned char>& vdata, const std::string& desturi);
    void UploadDataToController_UTF16(const std::vector<unsigned char>& vdata, const std::wstring& desturi);
    void UploadDirectoryToController_UTF8(const std::string& copydir, const std::string& desturi);
    void UploadDirectoryToController_UTF16(const std::wstring& copydir, const std::wstring& desturi);
    void DownloadFileFromController_UTF8(const std::string& desturi, std::vector<unsigned char>& vdata);
    void DownloadFileFromController_UTF16(const std::wstring& desturi, std::vector<unsigned char>& vdata);
    void DownloadFileFromControllerIfModifiedSince_UTF8(const std::string& desturi, long localtimeval, long &remotetimeval, std::vector<unsigned char>& vdata, double timeout);
    void DownloadFileFromControllerIfModifiedSince_UTF16(const std::wstring& desturi, long localtimeval, long &remotetimeval, std::vector<unsigned char>& vdata, double timeout);
    void DeleteFileOnController_UTF8(const std::string& desturi);
    void DeleteFileOnController_UTF16(const std::wstring& desturi);
    void DeleteDirectoryOnController_UTF8(const std::string& desturi);
    void DeleteDirectoryOnController_UTF16(const std::wstring& desturi);
    virtual void SetDefaultSceneType(const std::string& scenetype);
    virtual const std::string& GetDefaultSceneType();
    virtual void SetDefaultTaskType(const std::string& tasktype);
    virtual const std::string& GetDefaultTaskType();
    std::string GetScenePrimaryKeyFromURI_UTF8(const std::string& uri);
    std::string GetScenePrimaryKeyFromURI_UTF16(const std::wstring& uri);
    std::string GetPrimaryKeyFromName_UTF8(const std::string& name);
    std::string GetPrimaryKeyFromName_UTF16(const std::wstring& name);
    std::string GetNameFromPrimaryKey_UTF8(const std::string& pk);
    std::wstring GetNameFromPrimaryKey_UTF16(const std::string& pk);

    // controller client mock interface

private:
    std::string _dummy;
    std::wstring _wdummy;
};

typedef boost::shared_ptr<ControllerClientMock> ControllerClientImplPtr;

} // end namespace mujinclient

#endif
