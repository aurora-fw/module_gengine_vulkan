/****************************************************************************
** ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─
** ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐
** ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴
** A Powerful General Purpose Framework
** More information in: https://aurora-fw.github.io/
**
** Copyright (C) 2017 Aurora Framework, All rights reserved.
**
** This file is part of the Aurora Framework. This framework is free
** software; you can redistribute it and/or modify it under the terms of
** the GNU Lesser General Public License version 3 as published by the
** Free Software Foundation and appearing in the file LICENSE included in
** the packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
****************************************************************************/

#include <AuroraFW/GEngine/Vulkan/Context.h>

namespace AuroraFW {
	namespace GEngine {
		VKContext::VKContext(std::string &name)
			: _name(name)
		{
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		}

		void VKContext::_init()
		{
			vk::ApplicationInfo vk_appInfo(_name.c_str(), 0, "Aurora Framework", VK_MAKE_VERSION(AURORAFW_VERSION_MAJOR, AURORAFW_VERSION_MINOR, AURORAFW_VERSION_REVISION), VK_API_VERSION_1_0);

			vk::InstanceCreateInfo vk_createInfo(vk::InstanceCreateFlags(), &vk_appInfo);

			uint32_t glfwExtensionCount = 0;
			const char **glfwExtensions;
			glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
			vk_createInfo.enabledExtensionCount = glfwExtensionCount;
			vk_createInfo.ppEnabledExtensionNames = glfwExtensions;

			vk_createInfo.enabledLayerCount = 0;

			if(vk::createInstance(&vk_createInfo, AFW_NULLPTR, &_vkinstance) !=vk::Result::eSuccess)
				throw std::runtime_error("failed to create Vulkan instance!");
		}

		void VKContext::_destroy()
		{
			_vkinstance.destroy(AFW_NULLPTR);
		}
	}
}