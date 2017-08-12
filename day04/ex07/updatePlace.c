unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	return ((parkingRow & ~(1 << pos)) | (value << pos));
}
