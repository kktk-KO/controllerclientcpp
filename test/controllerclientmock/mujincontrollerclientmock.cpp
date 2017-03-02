// -*- coding: utf-8 -*-
// Copyright (C) 2017 MUJIN Inc.

#include <mujincontrollerclient/binpickingtask.h>
#include <mujincontrollerclient/mujincontrollerclient.h>

#include "logging.h"

MUJIN_LOGGER("mujin.testmujinvision.controllerclientmock");

namespace mujinclient {

ControllerClientPtr CreateControllerClient(const std::string& usernamepassword, const std::string& baseurl, const std::string& proxyserverport, const std::string& proxyuserpw, int options, double timeout)
{
  return ControllerClientPtr((ControllerClient *)(NULL));
}

}
