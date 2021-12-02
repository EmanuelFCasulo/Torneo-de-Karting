#include <iostream>
using namespace std;
#include <cstdlib>

int main()
{
    setlocale(LC_ALL, "Spanish");

    const int distancia=2000;
    int cod_participante, t_empleado,n_vuelta, descalificado, cod_participante_menor, cont_descalificados=0, cont_desc_ultima=0;
    float vel_media, ganador;
    bool b=0;


    cout<<"Ingrese el codigo del participante: ";
    cin>>cod_participante;

    while(cod_participante>=0)
    {

        int acu_t_empleado=0;
        float menor_tiempo;


        for(int x=0;x<4;x++)
        {
            cout<<"Ingrese el numero de vuelta: ";
            cin>>n_vuelta;
            cout<<"Ahora ingrese el tiempo empleado en minutos: ";
            cin>>t_empleado;
            cout<<"Fue descalificado? 1-Si, 0-No: ";
            cin>>descalificado;

            acu_t_empleado+=t_empleado;

            if(x==3 && descalificado==0)
            {
                cont_desc_ultima++;
            }
        }


        if(descalificado==0 && b==0)
        {
            menor_tiempo=acu_t_empleado;
            cod_participante_menor=cod_participante;
            b=1;

        }
        else
        {
            if(acu_t_empleado < menor_tiempo)
            {
                menor_tiempo=acu_t_empleado;
                cod_participante_menor=cod_participante;
            }
        }
        if(descalificado>0)
        {
            cont_descalificados++;
        }

        vel_media = (float)distancia / (acu_t_empleado * 60);
        cout<<"La velocidad media del participante "<<cod_participante<<" es de: "<<vel_media<<" Km/h"<<endl;

        ganador=menor_tiempo;

        cout<<"Ingrese el codigo del participante: ";
        cin>>cod_participante;
    }


    cout<<endl<<"El ganador de la competencia fue el participante numero "<<cod_participante_menor<<" con un tiempo total de: "<<ganador<<endl;
    cout<<"La cantidad total de participantes que fueron descalificados al menos 1 vez fueron: "<<cont_descalificados<<endl;
    cout<<"La cantidad total de participantes que no fueron descalificados en la ultima vuelta fueron: "<<cont_desc_ultima;

    system("pause>nul");
    return 0;
}
