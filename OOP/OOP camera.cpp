#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
class image{
public:
    double img [5][5];
    image & operator=(image &x) {
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                img[i][j]=x.img[i][j];
            }
        }
        return *this;
    }
};
class button
        {
        public:
            string type;
            bool state;
            void SetState();
            bool GetState();
        };
bool button::GetState() {
    if(state){
        cout << type << "turned on" << endl;
    }
    else {
        cout << type << "turned off" << endl;
    }
}
void button::SetState() {
    state=!state;
}
class timer{
public:
    timer();
    int maxTime;
    int time;
    bool SetTime();
    bool CountTime();

};
timer::timer() {
    maxTime=60;
    time=0;
}
bool timer::SetTime() {
    cout << "Enter time" << endl;
    cin >> time;
    if(time>maxTime){
        cout << "Max time is" << maxTime << "seconds" << " " << "set time less than max time" << endl;
        time=0;
        SetTime();
    }
    else
        {
        cout << "Timer is setted" << endl;
        return true;
    }

}
bool timer::CountTime() {
    while(time!=0){
        cout << time << " seconds remaining" << endl;
        time=time-1;
        Sleep(1000);
    }
    return true;
}
class Controler{
public:
    string type;
    double state;
void SetValue();
void GetValue();
};

void Controler::SetValue() {
      cout << "Enter value" << endl;
      cin >> state ;
}
void Controler::GetValue(){
    cout << type << " is "  << state << endl;
}
class film
{
public:
    film();
    int number;
    int photos;
    image* imgs;
    int lightsensivity;
    bool state;
    bool full();
    bool reactingtolight(image  x);
};
film::film() {
    number=20;
    imgs=new image[number];
    lightsensivity=120;
    state=false;
    photos=0;
}
bool film::reactingtolight(image  x) {
    if (state && number!=0) {
        if (lightsensivity > 25) {
            photos=photos+1;
            imgs[photos-1] = x;
            number = number - 1;


        } else {
            photos=photos+1;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    imgs[photos-1].img[i][j] = 0;
                }
            }
            number = number - 1;

        }
    }
}
bool film::full(){
    if(number==0){
        return false;
    }
    else
    {
        return true;
    }
}
class ControlSystem
{
public:
    ControlSystem();
    button trigger;
    timer timer;
    bool filmState;
    Controler shutterspeed;
    Controler diagraphm;
    Controler focus;
    bool filmRewind(film *);
};
ControlSystem::ControlSystem() {
    shutterspeed.state=0.5;
    focus.state=15;
    diagraphm.state=1;
    shutterspeed.type="Shutterspeed";
    focus.type="Focus";
    diagraphm.type="Diaphragm";
}

bool ControlSystem::filmRewind(film *x) {
    x->number=x->number+x->photos;
}


class Wire
{
public:
    Wire();
    string material;
};

Wire::Wire() {
material="brass";
}


class Rosette{
public:
    bool state;
    Rosette();
    bool GetState();
    void SetState();
};
Rosette::Rosette(){
    state=false;
};
bool Rosette::GetState() {
    if(state) {
        cout << "Rosette is on" << endl;
        return true;
    }
    else{
        cout << "Rosette is off" << endl;
        return false;
    }

}

void Rosette::SetState(){
    if(state){
        state= false;
        cout << "Rosette is unplugged" << endl;
    }
    else{
        state=true;
        cout << "Rosette is plugged" << endl;
    }

};

class PowerSupply
{
public:
    Wire wires;
    Rosette rosette;
    bool supplyEnergy();
};

bool PowerSupply::supplyEnergy() {
    if(rosette.state){
        cout << "Power is on!" << endl;
        return true;
    }
    else{
        cout << "Rosette is off!Plug in rosette" << endl;
        return false;
    }
}

class lens
{
public:
    lens();
    int number;
    int focallength;
    image  catchLight(ControlSystem *);
};


image  lens::catchLight(ControlSystem *x) {

    image a;


         for(int i=0;i<5;i++){
             for(int j=0;j<5;j++)
                 a.img[i][j]=x->diagraphm.state*x->focus.state;

         }



    return a;
}

lens::lens() {
focallength=125;
}


class OpticalSystem
{
public:
    film film;

    void TransferTheImageToFilm(ControlSystem *);
    lens lenses;
};

void OpticalSystem::TransferTheImageToFilm(ControlSystem * x) {
    if(film.state)
    film.reactingtolight(lenses.catchLight(x));
}

class flash
{
public:
    flash();
    bool state;
    PowerSupply power;
    bool toFlash();


};

flash::flash(){
    state=false;
}

bool flash::toFlash() {

    if(power.supplyEnergy()) {
        cout << "Flash!" << endl;
    }

}


class body
{
public:
   body();
    string material;
    bool tripodstate;
    bool tripod_mount();
    bool flash_mount(flash* f);
    bool film_replacement(film* x);

};
body::body() {
    tripodstate=false;


}
bool body::tripod_mount() {
    if(tripodstate){
        tripodstate=false;
        cout << "Tripod is unmounted" << endl;
    }
    else{
        tripodstate=true;
        cout << "Tripod mounted" << endl;
    }

}


bool body::film_replacement(film *x) {
    if(x->state){
        x->state=false;
        cout << "Film is replaced" << endl;
    }
    else
    {
        x->state=true;
        cout << "Film is plugged" << endl;
    }

}
bool body::flash_mount(flash* f) {
  if(f->state){
      f->state=!f->state;
      cout << "Flash is unmounted" << endl;
  }
  else{
      f->state=!f->state;
      cout << "Flash is mounted" << endl;
}
}

class MirrorSystem
{
public:
    MirrorSystem();
    bool state;
    bool imagetransmission(ControlSystem * y,OpticalSystem x);
};
MirrorSystem::MirrorSystem(){
    state=true;
}

bool MirrorSystem::imagetransmission(ControlSystem  *y,OpticalSystem x) {
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
           cout << x.lenses.catchLight(y).img[i][j] << " ";
        cout << endl;
    }



}

class camera{
public:
    bool state;
    body bd;
MirrorSystem ms;
ControlSystem cs;
flash fs;
OpticalSystem os;
bool ToPhotograph();
};
bool camera::ToPhotograph() {
    cs.trigger.SetState();
    ms.state=false;

    cs.timer.CountTime();
    if(fs.state){
        fs.toFlash();
    }
    Sleep(cs.shutterspeed.state);
    os.TransferTheImageToFilm(&cs);
    cout << "Shot taken!" << endl;
    ms.state=true;
    cs.trigger.SetState();


}
int main() {
    camera canon;
    int k;
    while(true) {
        cout << "What you want to do?:" << endl << "1-mount/unmount tripod" << endl << "2- mount/unmount flash" << endl
             << "3- set a film" << endl << "4-set a shutterspeed" << endl << "5- set a timer" << endl << "6-set a diaphragm" << endl << "7-set a focus" << endl
             << "8-on/off rosette of flash" << endl << "9-check rosette" <<  endl << "10 -check a view" << endl << "11-take a photo" << endl << "12-look at last photo" << endl
             <<"13-Check film" << endl << "14-check settings" <<  endl << "15-rewind the film" << endl;
        cin >> k;
        switch (k) {
            case 1:
                canon.bd.tripod_mount();
                break;
            case 2:
                canon.bd.flash_mount(&canon.fs);

                break;
            case 3:
                canon.bd.film_replacement(&canon.os.film);
                break;
            case 4:
                canon.cs.shutterspeed.SetValue();
                break;
            case 5:
                canon.cs.timer.SetTime();
                break;
            case 6:
                canon.cs.diagraphm.SetValue();
                break;
            case 7:
                canon.cs.focus.SetValue();
            case 8:
                canon.fs.power.rosette.SetState();
                break;
            case 9:
                canon.fs.power.rosette.GetState();
                break;
            case 10:
                canon.ms.imagetransmission(&canon.cs, canon.os);
                break;
            case 11:
                canon.ToPhotograph();
                break;
            case 12:
                if(canon.os.film.state && canon.os.film.photos>0) {
                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            cout << canon.os.film.imgs[canon.os.film.photos-1].img[i][j] << " ";

                        }
                        cout << endl;
                    }
                }
                else if(canon.os.film.photos<0){
                    cout << "No photos on this film" << endl;
                }
                else
                {
                    cout << "Film is missing" << endl;
                }
                break;
            case 13:
                if(canon.os.film.full()){
                    cout << "You can take " << canon.os.film.number << " photos" << endl;
                }
                else{
                    cout << "Film is full,reload" << endl;
                }
                break;
            case 14:
                canon.cs.diagraphm.GetValue();
                canon.cs.focus.GetValue();
                canon.cs.shutterspeed.GetValue();
                break;
            case 15:
                canon.cs.filmRewind(&canon.os.film);
            default:
                return 0;


        }
    }

}