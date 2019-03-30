#pragma once

#include "icolor.h"
#include <string>

namespace ColorSpaces
{
	class rgb_deepcolor : public icolor
	{
	public:
		rgb_deepcolor();
		rgb_deepcolor(float value);
		rgb_deepcolor(float value, float alpha);
		rgb_deepcolor(float r, float g, float b);
		rgb_deepcolor(float r, float g, float b, float a);
		rgb_deepcolor(const rgb_deepcolor& other);

		color_type get_color_type() override { return color_type::RGB_DEEP; }

		rgb_deepcolor& operator=(const rgb_deepcolor& other);
		
		float red();
		void red(float new_red);
		float green();
		void green(float new_green);
		float blue();
		void blue(float new_blue);
		float alpha();
		void alpha(float new_alpha);

	private:

	};
}