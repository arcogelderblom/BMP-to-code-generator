Example code for the use of this library:

int main( void ) {
	bitmap file(path_to_bitmap);
	int heigth = file.get_heigth();
	int width = file.get_width();
	std::cout<<"The heigth of the file is: "<<heigth<<" The width of the file is: "<<width<<'\n';
	file.use_nokia5510();
	file.get_black_pixels(path_to_outfile);
}

In the outfile there is now an array with x and y values of all the black pixels