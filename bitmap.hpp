/*
============================================================================
	File: 		bitmap.hpp
	Contains:	Everything to convert a bitmap to a array of 
	x and y coordinates which represent places of black pixels and
	some more things.
	Made by:	Arco Gelderblom 2016
	Distributed under the Boost Software License, Version 1.0.		
 	(See accompanying file LICENSE_1_0.txt in folder 'License' or 
	copy at http://www.boost.org/LICENSE_1_0.txt) 
============================================================================
*/
/// @file

#ifndef BITMAP_HPP
#define BITMAP_HPP

#include <iostream>
#include <fstream>
#include <windows.h>

/// Bitmap class
//
/// This class will let you open a bmp file, convert it to an array readable for c++ and some extra things like:
/// get the width, get the height, check if the image is compatible with a Nokia 5510
class bitmap {
private:
	/// Setup variable for input stream for the file
	std::ifstream file;
	/// Setup a char pointer for the filename to make sure it can be reused without continouisly asking a user to give it
	char * filename;
	/// Setup a variable for the width of the file
	long long int width;
	/// Setup a variable for the height of the file
	long long int heigth;
public:
	/// Constructor Bitmap
	//
	/// Call this to be sure that you can use your file. In the construcor the program will try to open the file and if it can be opened
	/// store some info about the file in the variables. If the file cant be opened the program will tell you this
	bitmap( char * filename );
	/// Check bitmap for use with a Nokia 5510 screen
	//
	/// This function uses the variables of width and height to check if the bitmap can be used with a Nokia 5510 screen.
	void use_nokia5510( void );
	/// Get width function
	//
	/// Returns the width of the image
	int get_width( void );
	/// Get height function
	//
	/// Returns the height of the image
	int get_heigth( void );
	/// Check the padding of the image
	//
	/// This function gets used internally in the program and is not necessary to call, it checks the padding so when indexing some bytes can be 
	/// skipped so it is possible to get the right information about the pixels out of the file
	int check_padding( void );
	/// Get the pixels function
	//
	/// This function makes a file following the c++ header file form and stores everything necessary in it to make sure it is possible to display the used bmp on a Nokia 5510 screen.
	void get_black_pixels( char * out_file );
};

#endif //BITMAP_HPP