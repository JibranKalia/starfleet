int occupiedPlaces(unsigned int parkingRow)
{
	int count = 0;
	while (parkingRow)
	{
		parkingRow = (parkingRow) & (parkingRow - 1);
		++count;
	}
	return (count);
}
