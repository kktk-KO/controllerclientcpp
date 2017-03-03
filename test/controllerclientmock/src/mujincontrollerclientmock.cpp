// -*- coding: utf-8 -*-
// Copyright (C) 2017 MUJIN Inc.
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

#include <mujincontrollerclient/binpickingtask.h>
#include <mujincontrollerclient/mujincontrollerclient.h>
#include <mujincontrollerclient/mujincontrollerclientmock.h>

#include "logging.h"

MUJIN_LOGGER("mujin.testmujinvision.controllerclientmock");

namespace mujinclient {


static ControllerClientMockPtr controllerClientMockSingleton = ControllerClientMockPtr(new ControllerClientMock);

ControllerClientPtr CreateControllerClient(const std::string& usernamepassword, const std::string& baseurl, const std::string& proxyserverport, const std::string& proxyuserpw, int options, double timeout)
{
  controllerClientMockSingleton->ControllerClientConstructor(usernamepassword, baseurl, proxyserverport, proxyuserpw, options, timeout);
  return controllerClientMockSingleton;
}

ControllerClientMockPtr GetControllerClientMockPtr()
{
  return controllerClientMockSingleton;
}

ControllerClientMockWeakPtr GetControllerClientMockWeakPtr()
{
  return controllerClientMockSingleton;
}

ControllerClientMock::ControllerClientMock()
{
}

ControllerClientMock::~ControllerClientMock()
{
}

void ControllerClientMock::ControllerClientConstructor(const std::string& usernamepassword, const std::string& baseurl, const std::string& proxyserverport, const std::string& proxyuserpw, int options, double timeout)
{
    return handler_ControllerClientConstructor(usernamepassword, baseurl, proxyserverport, proxyuserpw, options, timeout);
}

void ControllerClientMock::SetCharacterEncoding(const std::string& newencoding)
{
    return handler_SetCharacterEncoding(newencoding);
}

const std::string& ControllerClientMock::GetUserName() const
{
    return handler_GetUserName();
}

void ControllerClientMock::SetLanguage(const std::string& language)
{
    return handler_SetLanguage(language);
}

void ControllerClientMock::SetProxy(const std::string& serverport, const std::string& userpw)
{
    return handler_SetProxy(serverport, userpw);
}

void ControllerClientMock::RestartServer(double timeout)
{
    return handler_RestartServer(timeout);
}

void ControllerClientMock::Upgrade(const std::vector<unsigned char>& vdata)
{
    return handler_Upgrade(vdata);
    assert(false);
}

std::string ControllerClientMock::GetVersion()
{
    return handler_GetVersion();
}

void ControllerClientMock::CancelAllJobs()
{
    return handler_CancelAllJobs();
}

void ControllerClientMock::GetRunTimeStatuses(std::vector<JobStatus>& statuses, int options)
{
    return handler_GetRunTimeStatuses(statuses, options);
}

void ControllerClientMock::GetScenePrimaryKeys(std::vector<std::string>& scenekeys)
{
    return handler_GetScenePrimaryKeys(scenekeys);
}

SceneResourcePtr ControllerClientMock::RegisterScene_UTF8(const std::string& uri, const std::string& scenetype)
{
    return handler_RegisterScene_UTF8(uri, scenetype);
}

SceneResourcePtr ControllerClientMock::RegisterScene_UTF16(const std::wstring& uri, const std::string& scenetype)
{
    return handler_RegisterScene_UTF16(uri, scenetype);
}

SceneResourcePtr ControllerClientMock::ImportSceneToCOLLADA_UTF8(const std::string& importuri, const std::string& importformat, const std::string& newuri, bool overwrite)
{
    return handler_ImportSceneToCOLLADA_UTF8(importuri, importformat, newuri, overwrite);
}

SceneResourcePtr ControllerClientMock::ImportSceneToCOLLADA_UTF16(const std::wstring& importuri, const std::string& importformat, const std::wstring& newuri, bool overwrite)
{
    return handler_ImportSceneToCOLLADA_UTF16(importuri, importformat, newuri, overwrite);
}

void ControllerClientMock::SyncUpload_UTF8(const std::string& sourcefilename, const std::string& destinationdir, const std::string& scenetype)
{
    return handler_SyncUpload_UTF8(sourcefilename, destinationdir, scenetype);
}

void ControllerClientMock::SyncUpload_UTF16(const std::wstring& sourcefilename_utf16, const std::wstring& destinationdir_utf16, const std::string& scenetype)
{
    return handler_SyncUpload_UTF16(sourcefilename_utf16, destinationdir_utf16, scenetype);
}

void ControllerClientMock::UploadFileToController_UTF8(const std::string& filename, const std::string& desturi)
{
    return handler_UploadFileToController_UTF8(filename, desturi);
}
void ControllerClientMock::UploadFileToController_UTF16(const std::wstring& filename, const std::wstring& desturi)
{
    return handler_UploadFileToController_UTF16(filename, desturi);
}

void ControllerClientMock::UploadDataToController_UTF8(const std::vector<unsigned char>& vdata, const std::string& desturi)
{
    return handler_UploadDataToController_UTF8(vdata, desturi);
}

void ControllerClientMock::UploadDataToController_UTF16(const std::vector<unsigned char>& vdata, const std::wstring& desturi)
{
    return handler_UploadDataToController_UTF16(vdata, desturi);
}

void ControllerClientMock::UploadDirectoryToController_UTF8(const std::string& copydir, const std::string& desturi)
{
    return handler_UploadDirectoryToController_UTF8(copydir, desturi);
}

void ControllerClientMock::UploadDirectoryToController_UTF16(const std::wstring& copydir, const std::wstring& desturi)
{
    return handler_UploadDirectoryToController_UTF16(copydir, desturi);
}

void ControllerClientMock::DownloadFileFromController_UTF8(const std::string& desturi, std::vector<unsigned char>& vdata)
{
    return handler_DownloadFileFromController_UTF8(desturi, vdata);
}

void ControllerClientMock::DownloadFileFromController_UTF16(const std::wstring& desturi, std::vector<unsigned char>& vdata)
{
    return handler_DownloadFileFromController_UTF16(desturi, vdata);
}

void ControllerClientMock::DownloadFileFromControllerIfModifiedSince_UTF8(const std::string& desturi, long localtimeval, long &remotetimeval, std::vector<unsigned char>& vdata, double timeout)
{
    return handler_DownloadFileFromControllerIfModifiedSince_UTF8(desturi, localtimeval, remotetimeval, vdata, timeout);
}

void ControllerClientMock::DownloadFileFromControllerIfModifiedSince_UTF16(const std::wstring& desturi, long localtimeval, long &remotetimeval, std::vector<unsigned char>& vdata, double timeout)
{
    return handler_DownloadFileFromControllerIfModifiedSince_UTF16(desturi, localtimeval, remotetimeval, vdata, timeout);
}

void ControllerClientMock::DeleteFileOnController_UTF8(const std::string& desturi)
{
    return handler_DeleteFileOnController_UTF8(desturi);
}

void ControllerClientMock::DeleteFileOnController_UTF16(const std::wstring& desturi)
{
    return handler_DeleteFileOnController_UTF16(desturi);
}

void ControllerClientMock::DeleteDirectoryOnController_UTF8(const std::string& desturi)
{
    return handler_DeleteDirectoryOnController_UTF8(desturi);
}

void ControllerClientMock::DeleteDirectoryOnController_UTF16(const std::wstring& desturi)
{
    return handler_DeleteDirectoryOnController_UTF16(desturi);
}

void ControllerClientMock::SetDefaultSceneType(const std::string& scenetype)
{
    return handler_SetDefaultSceneType(scenetype);
}

const std::string& ControllerClientMock::GetDefaultSceneType()
{
    return handler_GetDefaultSceneType();
}

void ControllerClientMock::SetDefaultTaskType(const std::string& tasktype)
{
    return handler_SetDefaultTaskType(tasktype);
}

const std::string& ControllerClientMock::GetDefaultTaskType()
{
    return handler_GetDefaultTaskType();
}

std::string ControllerClientMock::GetScenePrimaryKeyFromURI_UTF8(const std::string& uri)
{
    return handler_GetScenePrimaryKeyFromURI_UTF8(uri);
}

std::string ControllerClientMock::GetScenePrimaryKeyFromURI_UTF16(const std::wstring& uri)
{
    return handler_GetScenePrimaryKeyFromURI_UTF16(uri);
}

std::string ControllerClientMock::GetPrimaryKeyFromName_UTF8(const std::string& name)
{
    return handler_GetPrimaryKeyFromName_UTF8(name);
}

std::string ControllerClientMock::GetPrimaryKeyFromName_UTF16(const std::wstring& name)
{
    return handler_GetPrimaryKeyFromName_UTF16(name);
}

std::string ControllerClientMock::GetNameFromPrimaryKey_UTF8(const std::string& pk)
{
    return handler_GetNameFromPrimaryKey_UTF8(pk);
}

std::wstring ControllerClientMock::GetNameFromPrimaryKey_UTF16(const std::string& pk)
{
    return handler_GetNameFromPrimaryKey_UTF16(pk);
}

} // namespace mujinclient
