#include <iostream>
#include <string>

/*Si en vez de imprimir el fondo en color se quiere imprimir sólo los caracteres,
hay que borrar el 30 y al <cuarenta y pico m> restarle 10 y dejar sólo ese número

Por ejemplo: "\e[0;32m" imprime texto normal (también se puede escribir como "\e[42m")
*/

#define NC "\e[0m"
#define RED "\e[41m"
#define GRN "\e[30;42m"
#define YLW "\e[1;30;43m"
#define BLU "\e[30;44m"
#define PUR "\e[30;45m"
#define CYN "\e[30;46m"
#define GRY "\e[30;47m"
#define LBL "\e[30;104m"
#define REDB "\e[41m"

using namespace std;

static const string color_keys[8] = {
	LBL,
	RED,
	GRN,
	YLW,
	BLU,
	PUR,
	CYN,
	GRY
};

static const string cuadro[] =
{
	"     ",
	"     ",
	"     "
};


class Imagen{

private:
	const string *figura;

public:
	Imagen(){figura = cuadro;}
	string filaArriba(){ return figura[0]; }
	string filaMedio(){ return figura[1]; }
	string filaAbajo(){ return figura[2]; }
	~Imagen(){}	
};

int main(int argc, char const *argv[]){
	Imagen im;
	
	for (size_t fil = 0; fil < 8; fil++){
		for (size_t i = 0; i < 8; i++){
			cout << color_keys[fil] << im.filaArriba() << NC << ' ' ;
		}
		cout << endl;
	}

	return 0;
}