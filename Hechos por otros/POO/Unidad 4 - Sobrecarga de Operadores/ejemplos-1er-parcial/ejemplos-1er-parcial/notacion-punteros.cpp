// Ej 3 (20pts) Escriba una funcion dosmin_down() que reciba un arreglo de
// flotantes de doble precisión como parámetro y su longitud. La función debe 
// ubicar el menor de la lista en el último lugar y al segundo menor en la 
// penúltima posición. Además, devuelve el menor. No utilice el operador [], 
// emplee notación de punteros para procesar el arreglo.
	
float dosmin_down(float *a, int n) {
	for (int n_trucha=n;n_trucha>=n-1;n--) {
		float menor=*a; int pos=0;
		for (int i=1;i<n_trucha;i++) {
			if (*(a+i)<menor) {
				menor=*(a+i);
				pos=i;
			}
		}
		*(a+pos)=*(a+n_trucha-1);
		*(a+n_trucha-1)=menor;
	}
	return *(a+n-1);
}


// otro ejemplo de notacion de punteros, pero con matrices, busca el menor en una de 10x10
float menor(float a[][10]) {
	float menor=**a;
	for (int i=0;i<10;i++) {
		for (int j=0;j<10;j++) {
			if (*(*(a+i)+j)<menor)
				menor=*(*(a+i)+j);
		}
	}
	return menor;
}
