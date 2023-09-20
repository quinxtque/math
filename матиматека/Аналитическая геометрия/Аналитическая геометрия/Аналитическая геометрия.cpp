#include <iostream>
#include <math.h>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	const int quantity = 3;
	float vec1[quantity];
	float vec2[quantity];
	float vec3[quantity];
	float xa, ya, za;
	float xb, yb, zb;
	float xc, yc, zc;

	// Ввод первого вектора
	cout << "Ввод первого вектора" << endl;

	cout << "Введите 'Xa': ";
	cin >> xa;

	cout << endl << "Введите 'Ya': ";
	cin >> ya;

	cout << endl << "Введите 'Za': ";
	cin >> za;

	// Ввод второго вектора
	cout << "Ввод второго вектора" << endl;

	cout << "Введите 'Xb': ";
	cin >> xb;

	cout << endl << "Введите 'Yb': ";
	cin >> yb;

	cout << endl << "Введите 'Zb': ";
	cin >> zb;

	// Ввод третьего вектора
	cout << "Ввод третьего вектора" << endl;

	cout << "Введите 'Xc': ";
	cin >> xc;

	cout << "Введите 'Yc': ";
	cin >> yc;

	cout << endl << "Введите 'Zc': ";
	cin >> zc;

	// Сборка массивов
	vec1[0] = xa; vec1[1] = ya; vec1[2] = za;
	vec2[0] = xb; vec2[1] = yb; vec2[2] = zb;
	vec3[0] = xc; vec3[1] = yc; vec3[2] = zc;

	// Нахождение длин рёбер 
	// vec1 = oa
	// vec2 = ob
	// vec3 = oc
	float oa, ob, oc, ab, bc, ca;

	oa = sqrt(xa * xa + ya * ya + za * za);
	ob = sqrt(xb * xb + yb * yb + zb * zb);
	oc = sqrt(xc * xc + yc * yc + zc * zc);
	ab = sqrt((vec2[0] - vec1[0]) * (vec2[0] - vec1[0]) + (vec2[1] - vec1[1]) * (vec2[1] - vec1[1]) + (vec2[2] - vec1[2]) * (vec2[2] - vec1[2]));
	bc = sqrt((vec3[0] - vec2[0]) * (vec3[0] - vec2[0]) + (vec3[1] - vec2[1]) * (vec3[1] - vec2[1]) + (vec3[2] - vec2[2]) * (vec3[2] - vec2[2]));
	ca = sqrt((vec1[0] - vec3[0]) * (vec1[0] - vec3[0]) + (vec1[1] - vec3[1]) * (vec1[1] - vec3[1]) + (vec1[2] - vec3[2]) * (vec1[2] - vec3[2]));

	cout << "а) Грани: " << endl;
	cout << "1-ая: " << oa << endl;
	cout << "2-ая: " << ob << endl;
	cout << "3-я: " << oc << endl;
	cout << "4-ая: " << ab << endl;
	cout << "5-ая: " << bc << endl;
	cout << "6-ая: " << ca << endl;

	//Величина углов в основании
	// сделать проверку на нулевые вектора
	float vec4[quantity], vec5[quantity], vec6[quantity];
	//    ab               bc               ca
	vec4[0] = vec2[0] - vec1[0];
	vec4[1] = vec2[1] - vec1[1]; // ab
	vec4[2] = vec2[2] - vec1[2];

	vec5[0] = vec3[0] - vec2[0];
	vec5[1] = vec3[1] - vec2[1]; // bc
	vec5[2] = vec3[2] - vec2[2];

	vec6[0] = vec1[0] - vec3[0];
	vec6[1] = vec1[1] - vec3[1]; // ca
	vec6[2] = vec1[2] - vec3[2];

	float cosCornerA, cosCornerB, cosCornerC;
	float cornerA, cornerB, cornerC;
	float AC[quantity], BA[quantity], CB[quantity];

	AC[0] = -vec6[0];
	AC[1] = -vec6[1];
	AC[2] = -vec6[2];

	if (AC[0] == AC[2] && vec4[0] == vec4[2]) {
		cout << "Векторы AC и AB нулевые" << endl;
	}
	else {
		cosCornerA = (vec4[0] * AC[0] + vec4[1] * AC[1] + vec4[2] * AC[2]) / ((sqrt(vec4[0] * vec4[0] + vec4[1] * vec4[1] + vec4[2] * vec4[2])) * (sqrt(AC[0] * AC[0] + AC[1] * AC[1] + AC[2] * AC[2])));
		cornerA = acos(cosCornerA);
		cout << "Угол при основании A (в радианах): " << cornerA << endl;
	}
	
	BA[0] = -vec4[0];
	BA[1] = -vec4[1];
	BA[2] = -vec4[2];

	if (BA[0] == BA[2] && vec5[0] == vec5[2]) {
		cout << "Векторы BA и BC нулевые" << endl;
	}
	else {
		cosCornerB = (BA[0] * vec5[0] + BA[1] * vec5[1] + BA[2] * vec5[2]) / ((sqrt(BA[0] * BA[0] + BA[1] * BA[1] + BA[2] * BA[2])) * (sqrt(vec5[0] * vec5[0] + vec5[1] * vec5[1] + vec5[2] * vec5[2])));
		cornerB = acos(cosCornerB);
		cout << "Угол при основании B (в радианах): " << cornerB << endl;
	}

	CB[0] = -vec5[0];
	CB[1] = -vec5[1];
	CB[2] = -vec5[2];

	if (CB[0] == CB[2] && vec6[0] == vec6[2]) {
		cout << "Векторы CB и CA нулевые" << endl;
	}
	else {
		cosCornerC = (vec6[0] * CB[0] + vec6[1] * CB[1] + vec6[2] * CB[2]) / ((sqrt(vec6[0] * vec6[0] + vec6[1] * vec6[1] + vec6[2] * vec6[2])) * (sqrt(CB[0] * CB[0] + CB[1] * CB[1] + CB[2] * CB[2])));
		cornerC = acos(cosCornerC);
		cout << "Угол при основании C (в радианах): " << cornerC << endl;
	}

	// Площадь боковой поверхности
	int iOAB, jOAB, kOAB,
		iOBC, jOBC, kOBC,
		iOAC, jOAC, kOAC;

	float sSideOAB, sSideOBC, sSideOAC, sSideFull;

	// OAB
	// Soab = |[vec1; vec2]|
	//          OA     OB
	iOAB = vec1[1] * vec2[2] - vec1[2] * vec2[1];
	jOAB = vec1[0] * vec2[2] - vec1[2] * vec2[0];
	kOAB = vec1[0] * vec2[1] - vec1[1] * vec2[0];

	sSideOAB = sqrt(iOAB * iOAB + jOAB * jOAB + kOAB * kOAB) / 2;
	cout << "Площадь OAB: " << sSideOAB << endl;

	// OBC
	// Sobc = |[vec2;vec3]|
	//           OB ; OC
	iOBC = vec2[1] * vec3[2] - vec3[2] * vec3[1];
	jOBC = vec2[0] * vec3[2] - vec2[2] * vec3[0];
	kOBC = vec2[0] * vec3[1] - vec2[1] * vec3[0];

	sSideOBC = sqrt(iOBC * iOBC + jOBC * jOBC + kOBC * kOBC) / 2;
	cout << "Площадь OBC: " << sSideOBC << endl;

	// OAC
	// Soac = |[vec1;vec3]|
	//           OA ; OC
	iOAC = vec1[1] * vec3[2] - vec1[2] * vec3[1];
	jOAC = vec1[0] * vec3[2] - vec1[2] * vec3[0];
	kOAC = vec1[0] * vec3[1] - vec1[1] * vec3[0];

	sSideOAC = sqrt(iOAC * iOAC + jOAC * jOAC + kOAC * kOAC) / 2;
	cout << "Площадь OAC: " << sSideOAC << endl;

	sSideFull = sSideOAB + sSideOBC + sSideOAC;
	cout << "Площадь боковой поверхности: " << sSideFull << endl;

	// Площадь основания
	// Sabc = |[vec4;AC]|
	//            AB;AC
	int iABC, jABC, kABC;
	float sBottom;

	iABC = vec4[1] * AC[2] - vec4[2] * AC[1];
	jABC = vec4[0] * AC[2] - vec4[2] * AC[0];
	kABC = vec4[0] * AC[1] - vec4[1] * AC[0];

	sBottom = sqrt(iABC * iABC + jABC * jABC + kABC * kABC) / 2;
	cout << "Площадь основания: " << sBottom << endl;

	// Площадь полной поверхности
	float sFull = sSideFull + sBottom;
	cout << "Площадь полной поверхности: " << sFull << endl;

	// Объём пирамиды
	// V = (BA; BC; BO)
	//		BA vec5 -OB
	// BA[0]     BA[1]     BA[2]
	// vec5[0]   vec5[1]   vec5[2]
	// -vec2[0]  -vec2[1]  -vec2[2]
	float v;
	v = ((BA[0] * vec5[1] * (-vec2[2]) + BA[1] * vec5[2] * (-vec2[0]) + BA[2] * vec5[0] * (-vec2[0])) - (BA[2] * vec5[1] * (-vec2[0]) + BA[1] * vec5[0] * (-vec2[2]) + BA[0] * vec5[2] * (-vec2[1]))) / 6;
	cout << "Объём пирамиды: " << v << endl;

	// Высоты из каждой вершины
	// h = sOAB / 0.5*oa
	float	hOAC, hOBC, hOAB,
			hAOB, hABC, hAOC,
			hBOC, hBOA, hBAC,
			hCAB, hCOB, hCOA;

	float ac = sqrt(AC[0] * AC[0] + AC[1] * AC[1] + AC[2] * AC[2]);
	hOAC = sSideOAC / (0.5 * ac);
	cout << "Высота из O на AC: " << hOAC << endl;

	hOBC = sSideOBC / (0.5 * bc);
	cout << "Высота из O на BC: " << hOBC << endl;

	hOAB = sSideOAB / (0.5 * ab);
	cout << "Высота из O на AB: " << hOAB << endl;

	hABC = sBottom / (0.5 * bc);
	cout << "Высота из A на BC: " << hABC << endl;

	hAOB = sSideOAB / (0.5 * ob);
	cout << "Высота из A на OB: " << hAOB << endl;

	hAOC = sSideOAC / (0.5 * oc);
	cout << "Высота из A на OC: " << hAOC << endl;

	hBOC = sSideOBC / (0.5 * oc);
	cout << "Высота из B на OC: " << hBOC << endl;

	hBOA = sSideOAB / (0.5 * oa);
	cout << "Высота из B на OA: " << hBOA << endl;
	
	hBAC = sBottom / (0.5 * ac);
	cout << "Высота из B на AC: " << hBAC << endl;

	hCAB = sBottom / (0.5 * ab);
	cout << "Высота из C на AB: " << hCAB << endl;

	hCOB = sSideOBC / (0.5 * ob);
	cout << "Высота из C на OB: " << hCOB << endl;

	hCOA = sSideOAC / (0.5 * oa);
	cout << "Высота из C на OA: " << hCOA << endl;

	return 0;
}