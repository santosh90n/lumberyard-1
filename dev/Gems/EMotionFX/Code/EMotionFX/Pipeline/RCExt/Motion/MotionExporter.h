/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#pragma once

#include <SceneAPI/SceneCore/Components/ExportingComponent.h>

namespace AZ
{
    namespace SceneAPI
    {
        namespace Events
        {
            class ExportEventContext;
        }
    }
}

namespace EMotionFX
{
    namespace Pipeline
    {
        class MotionExporter
            : public AZ::SceneAPI::SceneCore::ExportingComponent
        {
        public:
            AZ_COMPONENT(MotionExporter, "{A4F826D8-D710-4DF2-B660-9ED010072C1B}", AZ::SceneAPI::SceneCore::ExportingComponent);

            explicit MotionExporter();
            ~MotionExporter() override = default;

            static void Reflect(AZ::ReflectContext* context);

            AZ::SceneAPI::Events::ProcessingResult ProcessContext(AZ::SceneAPI::Events::ExportEventContext& context) const;

        private:
#if defined(AZ_COMPILER_MSVC) && AZ_COMPILER_MSVC <= 1800
            // Workaround for VS2013 - Delete the copy constructor and make it private
            // https://connect.microsoft.com/VisualStudio/feedback/details/800328/std-is-copy-constructible-is-broken
            MotionExporter(const MotionExporter&) = delete;
#endif
        };
    } // namespace Pipeline
} // namespace EMotionFX