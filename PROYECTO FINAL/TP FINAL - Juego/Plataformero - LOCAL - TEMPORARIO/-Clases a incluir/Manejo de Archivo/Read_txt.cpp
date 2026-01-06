#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Read_txt_File{
private:
	string file_name;
	vector<string>m_all_file;
	vector<string>m_current_platform;
	string aux_str;
	string aux_line_str;
	
	///int num_plat = 0;
	//int tamanio = 8;
	int tamanio_x = 8;
	int tamanio_y = 9;
public:
	Read_txt_File(string file_name);
	
};


int main() {
	Read_txt_File Leer_txt("Custom_Platform.txt");
	
	return 0;
}

Read_txt_File::Read_txt_File(string file_name){
	this->file_name = file_name;
	ifstream Archi_leer(file_name);
	if(!Archi_leer.is_open()){
		ofstream Archi_nuevo(file_name);
		Archi_nuevo<<"Leer plataformas customizadas"<<endl;
		Archi_nuevo<<endl;
		Archi_nuevo<<"//	'//' -> indica linea de comentarios	  	"<<endl;
		Archi_nuevo<<"// las plataformas usan:   		"<<endl;
		Archi_nuevo<<"//   'O' -> para bloques solidos	"<<endl;
		Archi_nuevo<<"//   '.' -> para para ausencia de bloques "<<endl;
		Archi_nuevo<<endl;
		Archi_nuevo<<"Ejemplo de una plataforma completa: "<<endl;
		Archi_nuevo<<endl;
		Archi_nuevo<<"	case 0: // No repetir numero, usar de la forma: 0,1,2,3,4,..."<<endl;
		Archi_nuevo<<"		//	  		 \"0123456789\" "<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[0]= \"........\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[1]= \"........\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[2]= \"........\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[3]= \"..OOOO..\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[4]= \"..OOOO..\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[5]= \"........\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[6]= \"........\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[7]= \"........\";"<<endl;
		Archi_nuevo<<"		Preset_Platform_Plat[8]= \"OOOOOOOO\";"<<endl;
		Archi_nuevo<<endl;
		Archi_nuevo<<"// lo que importa esta despues del signo igual"<<endl;
		Archi_nuevo<<"// las lineas de plataforma estan entre comillas dobles"<<endl;
		/*
	case 0:
		//			  			 "0123456789"
		Preset_Platform_Plat[0]= "........";
		Preset_Platform_Plat[1]= "........";
		Preset_Platform_Plat[2]= "........";
		Preset_Platform_Plat[3]= "........";
		Preset_Platform_Plat[4]= "........";
		Preset_Platform_Plat[5]= "........";
		Preset_Platform_Plat[6]= "........";
		Preset_Platform_Plat[7]= "........";
		Preset_Platform_Plat[8]= "OOOOOOOO";
		break;
		*/
		Archi_nuevo.close();
	}
	else{
		bool leer_siguiente = false;
		//while(Archi_leer >> aux_str){
		while(getline(Archi_leer, aux_line_str)){
			m_all_file.push_back(aux_line_str);
			//if(Archi_leer>> aux_str) /// si lee una palabra sigue (sino da error)
			/*
			if(leer_siguiente){
				if(aux_str == "\"")leer_siguiente = true;
				if else 
			}
			if(aux_str == "Preset_Platform_Plat[0]="){
				leer_siguiente = true;
			}
			*/
		}
		for(unsigned int i=0;i<m_all_file.size();i++) { 
			cout<<m_all_file[i]<<endl;
		}
		cout<<endl;
		
		Archi_leer.close();
	}
}
