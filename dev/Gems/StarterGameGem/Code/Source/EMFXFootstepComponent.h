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

#include <AzCore/Component/Component.h>

#include <Integration/AnimationBus.h>

namespace StarterGameGem
{
    class EMFXFootstepComponent
        : public AZ::Component
		, protected EMotionFX::Integration::ActorNotificationBus::Handler
	{
    public:
        AZ_COMPONENT(EMFXFootstepComponent, "{01654896-2D06-4B43-B184-8ED407B35AF5}");

        static void Reflect(AZ::ReflectContext* context);
		////////////////////////////////////////////////////////////////////////
		// ActorNotificationBus interface implementation
		void OnMotionEvent(EMotionFX::Integration::MotionEvent motionEvent) override;
		////////////////////////////////////////////////////////////////////////

    protected:

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
	private:
		void OnFootstepEvent(const char* eventName, const char* boneName, const char* fxLib);
    };
}
