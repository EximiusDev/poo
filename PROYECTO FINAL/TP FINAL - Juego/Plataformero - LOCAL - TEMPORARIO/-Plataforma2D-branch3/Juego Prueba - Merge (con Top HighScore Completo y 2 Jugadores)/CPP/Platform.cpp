#include "../H/Platform.h"

//#include "../H/Platform.h"
///Aca hay que hacerlo con puntero
///Podemos hacer que apraezcan con un timer
Platform::Platform() {
	cant_bloq_plat_y = 9;
	cant_bloq_plat = 24; /// maximo 32 = 16*2 =8*4 : es decir 4 plataformas predise�as mostrandose todo el tiempo
	
	pSet_Plat.Set_Predet_Plat(1);
	pSet_Plat_aux.Set_Predet_Plat(1);
	
	block_is_active.resize(cant_bloq_plat_y);
	for(int i=0;i<cant_bloq_plat_y;i++) { 
		block_is_active[i].resize(cant_bloq_plat);
	}
	for(int i=0;i<cant_bloq_plat_y;i++) { 
		for(int j=0;j<cant_bloq_plat;j++) { 
			block_is_active[i][j] = false;
			//cout<<" i: "<<i<<" j: "<<j<<endl;
		}
	}
	
	for(int j=0;j<cant_bloq_plat;j++) { 
		//block_is_active[4][j]= true;
		//block_is_active[5][j]= true;
		//block_is_active[6][j]= true;
		block_is_active[7][j]= true;
		//block_is_active[8][j]= true;
	}
	
	Plat0.resize(cant_bloq_plat);//Plat0.resize(16);
	Plat1.resize(cant_bloq_plat);
	Plat2.resize(cant_bloq_plat);//Plat2.resize(32);
	Plat3.resize(cant_bloq_plat);
	Plat4.resize(cant_bloq_plat);
	Plat5.resize(cant_bloq_plat);
	Plat6.resize(cant_bloq_plat);
	Plat7.resize(cant_bloq_plat);
	Plat8.resize(cant_bloq_plat);
	
	
	string Name4="./Textures/Tierra.png";
	/*for(int i=0;i<cant_bloq_plat;i++) { 
	string Name1="./Textures/Tierra";
	string Name2=to_string(1);
	string Name3=".png";
	string Name4=Name1+Name3;
	//Plat0[i].Init(Name4,i,8);
	Plat1[i].Init(Name4,i);
	//Plat2[i].Init(Name4,i,6);
	}*/
	//Texture textu;
	textu.loadFromFile(Name4);
	
	
	for(int j=0;j< cant_bloq_plat_y;j++) { 
		for(int i=0;i<this->Get_cant_bloq_plat(j);i++) {
			switch(j){
			case 0:
				Plat0[i].Init(textu,i,0);
				break;
			case 1:
				Plat1[i].Init(textu,i,1);
				break;
			case 2:
				Plat2[i].Init(textu,i,2);
				break;
			case 3:
				Plat3[i].Init(textu,i,3);
				break;
			case 4:
				Plat4[i].Init(textu,i,4);
				break;
			case 5:
				Plat5[i].Init(textu,i,5);
				break;
			case 6:
				Plat6[i].Init(textu,i,6);
				break;
			case 7:
				Plat7[i].Init(textu,i,7);
				break;
			case 8:
				Plat8[i].Init(textu,i,8);
				break;
				
			default:
				//Plat1[i].Init(textu,i);
				cerr<<"ERROR: cantidad de platafortmas incorrectas"<<endl;
			}
		}
	}
	Block_no_colition.Init(textu,-8,-8);
}
void Platform::Update(float velocity){
	/*
	for(int i=0;i<cant_bloq_plat;i++) { 
	Plat0[i].Update( 3 ); /// Velocidad (speed = -1* 3)
	Plat1[i].Update( 3 ); /// Velocidad (speed = -1* 3)
	Plat2[i].Update( 3 ); /// Velocidad (speed = -1* 3)
}*/
	/*
	if(Timer.getElapsedTime().asMilliseconds()>=500){
		Velocity.x=2;
		Timer.restart();
	}
	*/
	for(int j=0;j< cant_bloq_plat_y;j++) { 
		for(int i=0;i<this->Get_cant_bloq_plat(j);i++) {
			switch(j){
			case 0:
				Plat0[i].Update( velocity ); /// Velocidad (speed = -1* 3)
				break;
			case 1:
				Plat1[i].Update( velocity ); /// Velocidad (speed = -1* 3)
				break;
			case 2:
				Plat2[i].Update(velocity ); /// Velocidad (speed = -1* 3)
				break;
			case 3:
				Plat3[i].Update( velocity );
				break;
			case 4:
				Plat4[i].Update( velocity );
				break;
			case 5:
				Plat5[i].Update( velocity );
				break;
			case 6:
				Plat6[i].Update( velocity );
				break;
			case 7:
				Plat7[i].Update( velocity );
				break;
			case 8:
				Plat8[i].Update( velocity );
				break;
			default:
				//Plat1[i].Update( Velocity.x); /// Velocidad (speed = -1* 3)
				cerr<<"ERROR: cantidad de platafortmas incorrectas"<<endl;
			}
		}
	}
	//cout<<"velocity platform: "<<velocity<<endl;
	/// ///////////////////////////////////////////////////////////////////////////  " block_is_active.Update"
	
	if(Plat0[0].is_block_active()){
		Plat0[0].block_out_window(false);
		/// block_is_active: actualizo del 0 al 7 (8 bloques)
		for(int i=0;i<cant_bloq_plat_y;i++) { 
			for(int j=0;j<8;j++) { 
				//block_is_active[i][j] = true; /// semilla con nueva plataforma
				
				if(pSet_Plat.VerEsquemaBloq(j,i) == "O")  block_is_active[i][j] = true;
				else if(pSet_Plat.VerEsquemaBloq(j,i) == ".")  block_is_active[i][j] = false;
				//block_is_active[i][j] = pSet_Plat.VerTipoBloq(j,i); /// VerTipoBloq(j,i) = int x, int y
				//cout<<pSet_Plat.VerEsquemaBloq(j,i)<<"  ";
			}
		}
	}
	if(Plat0[8].is_block_active()){
		Plat0[8].block_out_window(false);
		for(int i=0;i<cant_bloq_plat_y;i++) { 
			for(int j=8;j<16;j++) { 
				//block_is_active[i][j] = false; // block_is_active[i][j]  //y, x
				
				if(pSet_Plat.VerEsquemaBloq(j-8,i) == "O")  block_is_active[i][j] = true;
				else if(pSet_Plat.VerEsquemaBloq(j-8,i) == ".")  block_is_active[i][j] = false;
				//block_is_active[i][j] = pSet_Plat.VerTipoBloq(j-8,i); /// VerTipoBloq(j,i) = int x, int y
				//cout<<pSet_Plat.VerEsquemaBloq(j-8,i)<<"  ";
			}
		}
	}
	if(Plat0[16].is_block_active()){
		Plat0[16].block_out_window(false);
		for(int i=0;i<cant_bloq_plat_y;i++) { 
			for(int j=16;j<24;j++) { 
				//cout<<i<<". ";
				if(pSet_Plat.VerEsquemaBloq(j-16,i) == "O")  block_is_active[i][j] = true;
				else if(pSet_Plat.VerEsquemaBloq(j-16,i) == ".")  block_is_active[i][j] = false;
				//block_is_active[i][j] = pSet_Plat.VerTipoBloq(j-16,i); /// VerTipoBloq(j,i) = int x, int y
				//cout<<pSet_Plat.VerEsquemaBloq(j-16,i)<<"  ";
				//cout<<j<<"  ";
			}
			//cout<<endl;
		}
	}
	pSet_Plat.Set_Predet_Plat(num_plat_rand);
	num_plat_rand = rand()%8 + 1; /// SEMILLA DE GENERACION ////////////////////////////////////////////////////
	
	/*
	if(this->VerEsquemaBloq(j,i)==".")MatrizBloq[i][j] = 0; // VerEsquemaBloq(j,i)(int x, int y)
	else if(this->VerEsquemaBloq(j,i)=="O")MatrizBloq[i][j] = 1;
	*/
}
/*
Bloque Platform::getBloq(int i){
return Plat1[i];
}*/
Bloque Platform::getBloq(int num_bloq_y, int _x){
	switch(num_bloq_y){
	case 0:
		if(block_is_active[num_bloq_y][_x]) return Plat0[_x];
		else return Block_no_colition;
		//break;
	case 1:
		if(block_is_active[num_bloq_y][_x]) return Plat1[_x];
		else return Block_no_colition;
		//break;
	case 2:
		if(block_is_active[num_bloq_y][_x]) return Plat2[_x];
		else return Block_no_colition;
		//break;
	case 3:
		if(block_is_active[num_bloq_y][_x]) return Plat3[_x];
		else return Block_no_colition;
		
	case 4:
		if(block_is_active[num_bloq_y][_x]) return Plat4[_x];
		else return Block_no_colition;
		
	case 5:
		if(block_is_active[num_bloq_y][_x]) return Plat5[_x];
		else return Block_no_colition;
		
	case 6:
		if(block_is_active[num_bloq_y][_x]) return Plat6[_x];
		else return Block_no_colition;
		
	case 7:
		if(block_is_active[num_bloq_y][_x]) return Plat7[_x];
		else return Block_no_colition;
		
	case 8:
		if(block_is_active[num_bloq_y][_x]) return Plat8[_x];
		else return Block_no_colition;
		
	default:
		return Block_no_colition;
		cerr<<"ERROR: cantidad de platafortmas incorrectas"<<endl;
	}
	
}

void Platform::Draw(RenderWindow & win){
	for(int j=0;j< cant_bloq_plat_y;j++) { 
		for(int i=0;i<this->Get_cant_bloq_plat(j);i++) {
			switch(j){
			case 0:
				//Plat0[i].Draw(win);
				Plat0[i].Draw(win, block_is_active[j][i]);
				break;
			case 1:
				Plat1[i].Draw(win, block_is_active[j][i]);
				break;
			case 2:
				Plat2[i].Draw(win, block_is_active[j][i]);
				break;
			case 3:
				Plat3[i].Draw(win, block_is_active[j][i]);
				break;
			case 4:
				Plat4[i].Draw(win, block_is_active[j][i]);
				break;
			case 5:
				Plat5[i].Draw(win, block_is_active[j][i]);
				break;
			case 6:
				Plat6[i].Draw(win, block_is_active[j][i]);
				break;
			case 7:
				Plat7[i].Draw(win, block_is_active[j][i]);
				break;
			case 8:
				Plat8[i].Draw(win, block_is_active[j][i]);
				break;
			default:
				//Plat1[i].Draw(win, true);
				//Plat1[i].Draw(win);
				cerr<<"ERROR: cantidad de platafortmas incorrectas"<<endl;
			}
		}
	}
	/*
	for(int i=0;i< cant_bloq_plat;i++) { 
	Plat0[i].Draw(win);
	Plat1[i].Draw(win);
	Plat2[i].Draw(win);
	
	}*/
}
int Platform::Get_cant_bloq_plat(int i){
	switch(i){
	case 0:
		return Plat0.size();
		//break;
	case 1:
		return Plat1.size();
		//break;
	case 2:
		return Plat2.size();
		//break;
	case 3:
		return Plat3.size();
		
	case 4:
		return Plat4.size();
		
	case 5:
		return Plat5.size();
		
	case 6:
		return Plat6.size();
		
	case 7:
		return Plat7.size();
		
	case 8:
		return Plat8.size();
		
	default:
		return cant_bloq_plat;
		cerr<<"ERROR: cantidad de platafortmas incorrectas"<<endl;
	}
}
int Platform::Get_cant_bloq_plat_y(){
	return cant_bloq_plat_y;
}
bool Platform::Get_block_existence(int i, int j){
	return block_is_active[i][j];
}
