#pragma once

// Atmospheric Constants
constexpr static float pb  = 101325; // [Pa] Pressure at Sea Level
constexpr static float Tb  = 288.15; // [K] Temperature at Sea Level
constexpr static float Lb  = -0.0065; // [K/m] Temp lapse rate
constexpr static float hb  = 0; // [m] Height at bottom of atmospheric layer
constexpr static float R   = 8.31432; // [N*m/mol*K] Universal Gas Constant
constexpr static float g_0 = 9.80665; // [m/s^2] Earth Standard Gravity
constexpr static float M   = 0.0289644; // [kg/mol] Molar mass of Earth's air