#pragma once

#include "..\utils\color_type.h"

#include <vector>

namespace color_space
{
	class icolor
	{
	public:
		icolor(int component_count, float component_max = 1.f, float component_min = 0.f)
		{
			m_max = component_max;
			m_min = component_min;

			for (auto i = 0; i < component_count; ++i)
			{
				m_component_vector.push_back(-1);
			}
		}

		virtual color_type get_color_type() const {
			return color_type::UNDEFINED;
		}

		virtual float get_component_max() const { return m_max; }
		virtual float get_component_min() const { return m_min; }

		friend bool operator==(const icolor& lhs, const icolor& rhs)
		{
			bool precondition = (lhs.get_color_type() == rhs.get_color_type()) && (lhs.m_component_vector.size() == rhs.m_component_vector.size());

			if (!precondition)
			{
				return false;
			}

			for (std::vector<float>::size_type i = 0; i < lhs.m_component_vector.size(); ++i)
			{
				if (lhs.m_component_vector[i] != rhs.m_component_vector[i])
				{
					return false;
				}
			}

			return true;
		}

		friend bool operator!=(const icolor& lhs, const icolor& rhs)
		{
			return !(lhs == rhs);
		}

		std::vector<float> m_component_vector;

	protected:
		float clamp(float in_value, float max, float min) { return fmaxf(fminf(in_value, max), min); }
		void set_component(float new_value, int index) { m_component_vector[index] = clamp(new_value, m_max, m_min); }
		void set_component(float new_value, int index, float max, float min) { m_component_vector[index] = clamp(new_value, max, min); }

		float m_max = 1.f;
		float m_min = 0.f;
	};
}