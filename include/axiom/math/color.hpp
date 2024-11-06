///////////////////////////////////////////////////////////////////////////////
///
/// MIT License
///
/// Copyright(c) 2024 Mallory SCOTTON
///
/// Permission is hereby granted, free of charge, to any person obtaining a
/// copy of this software and associated documentation files (the "Software"),
/// to deal in the Software without restriction, including without limitation
/// the rights to use, copy, modify, merge, publish, distribute, sublicense,
/// and/or sell copies of the Software, and to permit persons to whom the
/// Software is furnished to do so, subject to the following coditions:
///
/// The above copyright notice and this permission notice shall be included
/// in all copies or substantial portions of the Software?
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Pragma once
///////////////////////////////////////////////////////////////////////////////
#pragma once

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include <axiom/math/types.hpp>

///////////////////////////////////////////////////////////////////////////////
// Namespace ax::math
///////////////////////////////////////////////////////////////////////////////
namespace ax::math
{

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
struct Color
{
public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    union
    {
        struct
        {
            Uint8 a;    //<!
            Uint8 r;    //<!
            Uint8 g;    //<!
            Uint8 b;    //<!
        };
        Uint8 rgba[4];  //<!
        Uint32 bits;    //<!
    };

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    static const Color white;               //<!
	static const Color red;                 //<!
	static const Color green;               //<!
	static const Color blue;                //<!
	static const Color magenta;             //<!
	static const Color cyan;                //<!
	static const Color yellow;              //<!
	static const Color black;               //<!
	static const Color aquamarine;          //<!
	static const Color bakerChocolate;      //<!
	static const Color blueViolet;          //<!
	static const Color brass;               //<!
	static const Color brightGold;          //<!
	static const Color brown;               //<!
	static const Color bronze;              //<!
	static const Color bronzeIi;            //<!
	static const Color cadetBlue;           //<!
	static const Color coolCopper;          //<!
	static const Color copper;              //<!
	static const Color coral;               //<!
	static const Color cornFlowerBlue;      //<!
	static const Color darkBrown;           //<!
	static const Color darkGreen;           //<!
	static const Color darkGreenCopper;     //<!
	static const Color darkOliveGreen;      //<!
	static const Color darkOrchid;          //<!
	static const Color darkPurple;          //<!
	static const Color darkSlateBlue;       //<!
	static const Color darkSlateGrey;       //<!
	static const Color darkTan;             //<!
	static const Color darkTurquoise;       //<!
	static const Color darkWood;            //<!
	static const Color dimGrey;             //<!
	static const Color dustyRose;           //<!
	static const Color feldspar;            //<!
	static const Color firebrick;           //<!
	static const Color forestGreen;         //<!
	static const Color gold;                //<!
	static const Color goldenrod;           //<!
	static const Color grey;                //<!
	static const Color greenCopper;         //<!
	static const Color greenYellow;         //<!
	static const Color hunterGreen;         //<!
	static const Color indianRed;           //<!
	static const Color khaki;               //<!
	static const Color lightBlue;           //<!
	static const Color lightGrey;           //<!
	static const Color lightSteelBlue;      //<!
	static const Color lightWood;           //<!
	static const Color limeGreen;           //<!
	static const Color mandarianOrange;     //<!
	static const Color maroon;              //<!
	static const Color mediumAquamarine;    //<!
	static const Color mediumBlue;          //<!
	static const Color mediumForestGreen;   //<!
	static const Color mediumGoldenrod;     //<!
	static const Color mediumOrchid;        //<!
	static const Color mediumSeaGreen;      //<!
	static const Color mediumSlateBlue;     //<!
	static const Color mediumSpringGreen;   //<!
	static const Color mediumTurquoise;     //<!
	static const Color mediumVioletRed;     //<!
	static const Color mediumWood;          //<!
	static const Color midnightBlue;        //<!
	static const Color navyBlue;            //<!
	static const Color neonBlue;            //<!
	static const Color neonPink;            //<!
	static const Color newMidnightBlue;     //<!
	static const Color newTan;              //<!
	static const Color oldGold;             //<!
	static const Color orange;              //<!
	static const Color orangeRed;           //<!
	static const Color orchid;              //<!
	static const Color paleGreen;           //<!
	static const Color pink;                //<!
	static const Color plum;                //<!
	static const Color quartz;              //<!
	static const Color richBlue;            //<!
	static const Color salmon;              //<!
	static const Color scarlet;             //<!
	static const Color seaGreen;            //<!
	static const Color semiSweetChocolate;  //<!
	static const Color sienna;              //<!
	static const Color silver;              //<!
	static const Color skyBlue;             //<!
	static const Color slateBlue;           //<!
	static const Color spicyPink;           //<!
	static const Color springGreen;         //<!
	static const Color steelBlue;           //<!
	static const Color summerSky;           //<!
	static const Color tan;                 //<!
	static const Color thistle;             //<!
	static const Color turquoise;           //<!
	static const Color veryDarkBrown;       //<!
	static const Color veryLightGrey;       //<!
	static const Color violet;              //<!
	static const Color violetRed;           //<!
	static const Color wheat;               //<!
	static const Color yellowGreen;         //<!

public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    ///////////////////////////////////////////////////////////////////////////
    Color(void);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param r
    /// \param g
    /// \param b
    /// \param a
    ///
    ///////////////////////////////////////////////////////////////////////////
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief
    ///
    /// \param color
    ///
    ///////////////////////////////////////////////////////////////////////////
    Color(Uint32 color);
};

} // namespace ax::math
