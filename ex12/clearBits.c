unsigned int clearBits(unsigned int parkingRow, int n)
{
	unsigned int tmp = 1 << n;
	tmp = tmp - 1;
	return (parkingRow & ~tmp);
}
