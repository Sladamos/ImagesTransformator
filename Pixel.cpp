#include "Pixel.h"

uint8_t Pixel::getColorValue(Color color) const
{
	switch (color)
	{
	case Color::red:
		return R;
	case Color::green:
		return G;
	case Color::blue:
		return B;
	}
}