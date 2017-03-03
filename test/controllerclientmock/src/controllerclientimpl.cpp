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

#include "controllerclientimpl.h"

#include <boost/algorithm/string.hpp>

#include "logging.h"

MUJIN_LOGGER("mujin.testmujinvision.controllerclientmock");

namespace mujinclient {

ControllerClientMock::ControllerClientMock(const std::string& usernamepassword, const std::string& baseuri, const std::string& proxyserverport, const std::string& proxyuserpw, int options, double timeout)
{
}

ControllerClientMock::~ControllerClientMock()
{
}

void ControllerClientMock::SetCharacterEncoding(const std::string& newencoding)
{
    assert(false);
}

const std::string& ControllerClientMock::GetUserName() const
{
    assert(false);
    return _dummy;
}

void ControllerClientMock::SetLanguage(const std::string& language)
{
    assert(false);
}

void ControllerClientMock::SetProxy(const std::string& serverport, const std::string& userpw)
{
    assert(false);
}

void ControllerClientMock::RestartServer(double timeout)
{
    assert(false);
}

void ControllerClientMock::Upgrade(const std::vector<unsigned char>& vdata)
{
    assert(false);
}

std::string ControllerClientMock::GetVersion()
{
    assert(false);
    return std::string("dummy");
}

void ControllerClientMock::CancelAllJobs()
{
    assert(false);
}

void ControllerClientMock::GetRunTimeStatuses(std::vector<JobStatus>& statuses, int options)
{
    assert(false);
}

void ControllerClientMock::GetScenePrimaryKeys(std::vector<std::string>& scenekeys)
{
    assert(false);
}

SceneResourcePtr ControllerClientMock::RegisterScene_UTF8(const std::string& uri, const std::string& scenetype)
{
    assert(false);
    return SceneResourcePtr();
}

SceneResourcePtr ControllerClientMock::RegisterScene_UTF16(const std::wstring& uri, const std::string& scenetype)
{
    assert(false);
    return SceneResourcePtr();
}

SceneResourcePtr ControllerClientMock::ImportSceneToCOLLADA_UTF8(const std::string& importuri, const std::string& importformat, const std::string& newuri, bool overwrite)
{
    assert(false);
    return SceneResourcePtr();
}

SceneResourcePtr ControllerClientMock::ImportSceneToCOLLADA_UTF16(const std::wstring& importuri, const std::string& importformat, const std::wstring& newuri, bool overwrite)
{
    assert(false);
    return SceneResourcePtr();
}

void ControllerClientMock::SyncUpload_UTF8(const std::string& _sourcefilename, const std::string& destinationdir, const std::string& scenetype)
{
    assert(false);
}

void ControllerClientMock::SyncUpload_UTF16(const std::wstring& _sourcefilename_utf16, const std::wstring& destinationdir_utf16, const std::string& scenetype)
{
    assert(false);
}

void ControllerClientMock::UploadFileToController_UTF8(const std::string& filename, const std::string& desturi)
{
    assert(false);
}
void ControllerClientMock::UploadFileToController_UTF16(const std::wstring& filename, const std::wstring& desturi)
{
    assert(false);
}

void ControllerClientMock::UploadDataToController_UTF8(const std::vector<unsigned char>& vdata, const std::string& desturi)
{
    assert(false);
}

void ControllerClientMock::UploadDataToController_UTF16(const std::vector<unsigned char>& vdata, const std::wstring& desturi)
{
    assert(false);
}

void ControllerClientMock::UploadDirectoryToController_UTF8(const std::string& copydir, const std::string& desturi)
{
    assert(false);
}

void ControllerClientMock::UploadDirectoryToController_UTF16(const std::wstring& copydir, const std::wstring& desturi)
{
    assert(false);
}

void ControllerClientMock::DownloadFileFromController_UTF8(const std::string& desturi, std::vector<unsigned char>& vdata)
{
    assert(false);
}

void ControllerClientMock::DownloadFileFromController_UTF16(const std::wstring& desturi, std::vector<unsigned char>& vdata)
{
    assert(false);
}

void ControllerClientMock::DownloadFileFromControllerIfModifiedSince_UTF8(const std::string& desturi, long localtimeval, long &remotetimeval, std::vector<unsigned char>& vdata, double timeout)
{
    assert(false);
}

void ControllerClientMock::DownloadFileFromControllerIfModifiedSince_UTF16(const std::wstring& desturi, long localtimeval, long &remotetimeval, std::vector<unsigned char>& vdata, double timeout)
{
    assert(false);
}

void ControllerClientMock::DeleteFileOnController_UTF8(const std::string& desturi)
{
    assert(false);
}

void ControllerClientMock::DeleteFileOnController_UTF16(const std::wstring& desturi)
{
    assert(false);
}

void ControllerClientMock::DeleteDirectoryOnController_UTF8(const std::string& desturi)
{
    assert(false);
}

void ControllerClientMock::DeleteDirectoryOnController_UTF16(const std::wstring& desturi)
{
    assert(false);
}

void ControllerClientMock::SetDefaultSceneType(const std::string& scenetype)
{
    assert(false);
}

const std::string& ControllerClientMock::GetDefaultSceneType()
{
    assert(false);
    return _dummy;
}

void ControllerClientMock::SetDefaultTaskType(const std::string& tasktype)
{
    assert(false);
}

const std::string& ControllerClientMock::GetDefaultTaskType()
{
    assert(false);
    return _dummy;
}

std::string ControllerClientMock::GetScenePrimaryKeyFromURI_UTF8(const std::string& uri)
{
    assert(false);
    return std::string("dummy");
}

std::string ControllerClientMock::GetScenePrimaryKeyFromURI_UTF16(const std::wstring& uri)
{
    assert(false);
    return std::string("dummy");
}

std::string ControllerClientMock::GetPrimaryKeyFromName_UTF8(const std::string& name)
{
    assert(false);
    return std::string("dummy");
}

std::string ControllerClientMock::GetPrimaryKeyFromName_UTF16(const std::wstring& name)
{
    assert(false);
    return std::string("dummy");
}

std::string ControllerClientMock::GetNameFromPrimaryKey_UTF8(const std::string& pk)
{
    assert(false);
    return std::string("dummy");
}

std::wstring ControllerClientMock::GetNameFromPrimaryKey_UTF16(const std::string& pk)
{
    assert(false);
    return std::wstring(L"dummy");
}

} // end namespace mujinclient
