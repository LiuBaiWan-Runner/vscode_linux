#include <iostream>
using namespace std;
//通过高斯消元法化矩阵为upper triangle matrix
void GaussElimination2UTM(double* matrix, int dimension){
	//注意cnt3一定要从矩阵最右侧运算至左侧，否则主元列对应元素归零，运算就无法正常进行
	for(int cnt1=0; cnt1<dimension; cnt1++) for(int cnt2=cnt1+1; cnt2<dimension; cnt2++) for(int cnt3=dimension-1; cnt3>=cnt1; cnt3--)
		matrix[cnt2*dimension+cnt3] += -1*matrix[cnt1*dimension+cnt3]*matrix[cnt2*dimension+cnt1]/matrix[cnt1*dimension+cnt1];
	return;
}
double Determinant(double* matrix, int dimension){
	double determinant=1;
	GaussElimination2UTM(matrix, dimension);
	//上三角阵对角线乘积即为行列式
	for(int cnt=0; cnt<dimension; cnt++) determinant *= matrix[cnt*dimension+cnt];

	return determinant;
}


int main(){
    int n;
    for(int i = 0; i < n; i++){
        int dimension;
        int scale;
        
        cin >> dimension;
        scale = dimension*dimension;
        double matrix[scale];
        for(int cnt=0; cnt<scale; cnt++){
            cin >> matrix[cnt];
        }
        cout << Determinant(matrix, dimension) << endl;
    }
	return 0;
}
