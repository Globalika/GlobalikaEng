#pragma once

#include "Globalika/Layer.h"

#include "Globalika/Events/KeyEvent.h"
#include "Globalika/Events/MouseEvent.h"
#include "Globalika/Events/ApplicationEvent.h"

namespace Globalika {
	class GLOBALIKA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}