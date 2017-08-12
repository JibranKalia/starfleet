
unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	int tmp = (1 << pos);
	return (parkingRow ^ tmp);
}
