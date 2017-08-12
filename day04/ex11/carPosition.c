int powerof2(unsigned int n)
{
	if (n == 1)
		return (1);
	if ((n & (n - 1)) == 0)
		return (1);
	return (-1);
}

int carPosition(unsigned int parkingRow)
{
	if (powerof2(parkingRow) == -1)
		return (-1);
	unsigned int count = 0;
	while (parkingRow)
	{
		parkingRow /= 2;
		++count;
	}
	return (count - 1);
}
