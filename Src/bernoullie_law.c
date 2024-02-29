/*
 * bernoullie_law.c
 *
 *  Created on: 14 lut 2024
 *      Author: majorBien
 */


	/*
	    Dla powietrza sprężonego przy temperaturze pokojowej (około 20 stopni Celsjusza), wartość lepkości dynamicznej wynosi około 1.8 x 10^-5 Pa·s.
	    Jeśli promień węża jest równy 6mm (czyli 0.006m), możemy obliczyć wartość k na podstawie danych:

		k = 32 * μ * L / (r^4)

		gdzie:
		μ = 1.8 x 10^-5 Pa·s, - 0.000018
		r = 0.006m (średnica 6mm),
		L - odległość między dwoma presostatami 0.05m

		P2 - P1 = k * (r^4) / (8 * μ * L)

		Aby obliczyć ciśnienie zadane przez regulator, możemy przekształcić to równanie:

		P_regulator = P1 + (k * (r^4) / (8 * μ * L) / 2)

		gdzie:
		P1 - ciśnienie przy pierwszym presostacie,
		k - stała proporcjonalności,
		r - promień węża,
		μ - lepkość dynamiczna gazu,
		L - odległość między dwoma presostatami.


	    */


double BernoulieLawFunction(double pressure1, double pressure2, double air_viscosity, double tubeRadius, double distance)
{
	double delta_air = pressure1 - pressure2;

	double k = 32 * air_viscosity * distance / (tubeRadius*tubeRadius*tubeRadius*tubeRadius);
	double regulator_pressure = pressure1 + (k * (tubeRadius*tubeRadius*tubeRadius*tubeRadius) / (8 * air_viscosity * distance) / 2) + delta_air;

	return regulator_pressure;
}
