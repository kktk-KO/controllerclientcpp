// -*- coding: utf-8 -*-
// Copyright (C) 2017 MUJIN Inc.

/** \file controllerclientimpl.h
    \brief  Private header file implementing the ControllerClient interface
 */

#ifndef MUJIN_CONTROLLERCLIENT_IMPL_H
#define MUJIN_CONTROLLERCLIENT_IMPL_H

#include <mujincontrollerclient/mujincontrollerclient.h>

#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>

namespace mujinclient {

/// \brief ControllerClientMock is expected to be signleton for now.
///  in order to get reference to the singleton, use GetControllerClientMockPtr.
class ControllerClientMock : public ControllerClient, public boost::enable_shared_from_this<ControllerClientMock>
{
public:
    ControllerClientMock();
    virtual ~ControllerClientMock();

    // controller client interface

    /// this method is the customization point for CreateControllerClient.
    void ControllerClientConstructor(const std::string& usernamepassword, const std::string& baseurl, const std::string& proxyserverport, const std::string& proxyuserpw, int options, double timeout);
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
    void SetDefaultSceneType(const std::string& scenetype);
    const std::string& GetDefaultSceneType();
    void SetDefaultTaskType(const std::string& tasktype);
    const std::string& GetDefaultTaskType();
    std::string GetScenePrimaryKeyFromURI_UTF8(const std::string& uri);
    std::string GetScenePrimaryKeyFromURI_UTF16(const std::wstring& uri);
    std::string GetPrimaryKeyFromName_UTF8(const std::string& name);
    std::string GetPrimaryKeyFromName_UTF16(const std::wstring& name);
    std::string GetNameFromPrimaryKey_UTF8(const std::string& pk);
    std::wstring GetNameFromPrimaryKey_UTF16(const std::string& pk);

    // controller client mock interface

    boost::function<void(const std::string&, const std::string&, const std::string&, const std::string&, int, double)> handler_ControllerClientConstructor;
    boost::function<void(const std::string&)> handler_SetCharacterEncoding;
    boost::function<const std::string&()> handler_GetUserName;
    boost::function<void(const std::string&)> handler_SetLanguage;
    boost::function<void(const std::string&, const std::string&)> handler_SetProxy;
    boost::function<void(double)> handler_RestartServer;
    boost::function<void(const std::vector<unsigned char>&)> handler_Upgrade;
    boost::function<std::string()> handler_GetVersion;
    boost::function<void()> handler_CancelAllJobs;
    boost::function<void(std::vector<JobStatus>&, int)> handler_GetRunTimeStatuses;
    boost::function<void(std::vector<std::string>&)> handler_GetScenePrimaryKeys;
    boost::function<SceneResourcePtr(const std::string&, const std::string)> handler_RegisterScene_UTF8;
    boost::function<SceneResourcePtr(const std::wstring&, const std::string)> handler_RegisterScene_UTF16;
    boost::function<SceneResourcePtr(const std::string&, const std::string, const std::string&, bool overwrite)> handler_ImportSceneToCOLLADA_UTF8;
    boost::function<SceneResourcePtr(const std::wstring&, const std::string, const std::wstring&, bool overwrite)> handler_ImportSceneToCOLLADA_UTF16;
    boost::function<void(const std::string&, const std::string&, const std::string&)> handler_SyncUpload_UTF8;
    boost::function<void(const std::wstring&, const std::wstring&, const std::string&)> handler_SyncUpload_UTF16;
    boost::function<void(const std::string&, const std::string&)> handler_UploadFileToController_UTF8;
    boost::function<void(const std::wstring&, const std::wstring&)> handler_UploadFileToController_UTF16;
    boost::function<void(const std::vector<unsigned char>&, const std::string&)> handler_UploadDataToController_UTF8;
    boost::function<void(const std::vector<unsigned char>&, const std::wstring&)> handler_UploadDataToController_UTF16;
    boost::function<void(const std::string&, const std::string&)> handler_UploadDirectoryToController_UTF8;
    boost::function<void(const std::wstring&, const std::wstring&)> handler_UploadDirectoryToController_UTF16;
    boost::function<void(const std::string&, std::vector<unsigned char>&)> handler_DownloadFileFromController_UTF8;
    boost::function<void(const std::wstring&, std::vector<unsigned char>&)> handler_DownloadFileFromController_UTF16;
    boost::function<void(const std::string&, long, long, std::vector<unsigned char>&, double)> handler_DownloadFileFromControllerIfModifiedSince_UTF8;
    boost::function<void(const std::wstring&, long, long, std::vector<unsigned char>&, double)> handler_DownloadFileFromControllerIfModifiedSince_UTF16;
    boost::function<void(const std::string&)> handler_DeleteFileOnController_UTF8;
    boost::function<void(const std::wstring&)> handler_DeleteFileOnController_UTF16;
    boost::function<void(const std::string&)> handler_DeleteDirectoryOnController_UTF8;
    boost::function<void(const std::wstring&)> handler_DeleteDirectoryOnController_UTF16;
    boost::function<void(const std::string&)> handler_SetDefaultSceneType;
    boost::function<const std::string&()> handler_GetDefaultSceneType;
    boost::function<void(const std::string&)> handler_SetDefaultTaskType;
    boost::function<const std::string&()> handler_GetDefaultTaskType;
    boost::function<std::string(const std::string&)> handler_GetScenePrimaryKeyFromURI_UTF8;
    boost::function<std::string(const std::wstring&)> handler_GetScenePrimaryKeyFromURI_UTF16;
    boost::function<std::string(const std::string&)> handler_GetPrimaryKeyFromName_UTF8;
    boost::function<std::string(const std::wstring&)> handler_GetPrimaryKeyFromName_UTF16;
    boost::function<std::string(const std::string&)> handler_GetNameFromPrimaryKey_UTF8;
    boost::function<std::wstring(const std::string&)> handler_GetNameFromPrimaryKey_UTF16;
};

typedef boost::shared_ptr<ControllerClientMock> ControllerClientMockPtr;
typedef boost::weak_ptr<ControllerClientMock> ControllerClientMockWeakPtr;

ControllerClientMockPtr GetControllerClientMockPtr();
ControllerClientMockWeakPtr GetControllerClientMockWeakPtr();

} // end namespace mujinclient

#endif
