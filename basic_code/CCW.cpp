typedef pair<double, double> dd;
double CCW(dd a, dd b, dd c) {
	double result = a.first * b.second + b.first * c.second + c.first * a.second;
	result -= (a.second * b.first + b.second * c.first + c.second * a.first);
	return result;
}
// the result indicates double of the area for triangle (a,b,c)
// 
