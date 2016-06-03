#pragma once


namespace sg
{

	struct Color
	{
		Color() {}
		Color(int _r, int _g, int _b)
		{
			r = _r; 
			g = _g; 
			b = _b;
		}
		int r = 0;
		int g = 0;
		int b = 0;
	};

}