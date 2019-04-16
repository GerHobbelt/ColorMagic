/// Copyright Martin Ruehlicke, 2019
/// Use, modification and distribution are subject to the
/// MIT Software License, Version 1.0.
/// See accompanying file LICENSE.txt

#pragma once

#include "color_base.h"
#include <string>
#include <vector>

namespace color_space
{
	//! Color space to represents grey deep colors.
		/*!
		* This class holds getters and setters for grey value, alpha and various constructors.
		*/
	class grey_deepcolor : public color_base
	{
	public:
		//! Default constructor.
		/*!
		* Sets grey and alpha value.
		* \param value The value that will be set for grey value (default 0).
		* \param alpha The value that will be set for alpha (default 1).
		*/
		grey_deepcolor(float value = 0.f, float alpha = 1.f);

		//! Default copy constructor.
		/*!
		* Constructs a grey color from a given one.
		* \param other The grey object to construct this color from.
		*/
		grey_deepcolor(const grey_deepcolor& other);

		//! Default copy constructor.
		/*!
		* Constructs a grey color from a color_base object.
		* \param other The color_base object to construct this color from.
		*/
		grey_deepcolor(const color_base& other);

		//! Assignment operator overload.
		/*!
		* Assigns the components from the right hand object to the corresponding components of the left hand object.
		* \param other The grey_deepcolor object to get the component values from.
		*/
		grey_deepcolor& operator=(const grey_deepcolor& other);
		
		//! Getter for grey component.
		//! \return The grey component of this color.
		float grey();

		//! Setter for grey component.
		//! \param new_grey The grey value to set.
		void grey(float new_grey);

		//! Getter for alpha component.
		//! \return The alpha component of this color.
		float alpha();

		//! Setter for alpha component.
		//! \param new_alpha The alpha value to set.
		void alpha(float new_alpha);

	private:

	};
}