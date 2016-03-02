#include "CSerial.cpp"
#include <fltk/run.h>
#include <fltk/Window.h>
#include <fltk/ScrollGroup.h>
#include <fltk/Button.h>
#include <fltk/ReturnButton.h>
#include <fltk/Input.h>
#include <fltk/IntInput.h>
#include <fltk/ask.h>
#include <fltk/events.h>
#include <fltk/file_chooser.h>
#include <fltk/Choice.h>
#include <fltk/Widget.h>
#include <fltk/CheckButton.h>
#include <fltk/PopupMenu.h>
#include <fltk/xpmImage.h>
#include <fltk/Font.h>
#include <fltk/draw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simb1.xpm"
#include "simb2.xpm"
#include "simb3.xpm"
#include "simb4.xpm"
#include "simb5.xpm"
#include "simb6.xpm"
#include "simb7.xpm"
#include "simb8.xpm"
#include "simb9.xpm"
#include "simb10.xpm"
#include "simb11.xpm"
#include "simb12.xpm"
#include "simb13.xpm"
#include "simb14.xpm"
#include "simb15.xpm"
#include "simb16.xpm"
#include "simb17.xpm"
#include "simb18.xpm"
#include "simb19.xpm"
#include "simb20.xpm"
#include "simb21.xpm"
#include "simb22.xpm"
#include "simb23.xpm"
#include "simb24.xpm"
#include "simb25.xpm"
#include "simb26.xpm"
#include "simb27.xpm"
#include "simb28.xpm"
#include "simb29.xpm"
#include "simb30.xpm"
#include "simb31.xpm"

using namespace fltk;
static xpmImage *simboli[] = {new xpmImage(simb1_xpm), new xpmImage(simb2_xpm), new xpmImage(simb3_xpm), new xpmImage(simb4_xpm), new xpmImage(simb5_xpm), new xpmImage(simb6_xpm), new xpmImage(simb7_xpm), new xpmImage(simb8_xpm), new xpmImage(simb9_xpm), new xpmImage(simb10_xpm), new xpmImage(simb11_xpm), new xpmImage(simb12_xpm), new xpmImage(simb13_xpm), new xpmImage(simb14_xpm), new xpmImage(simb15_xpm), new xpmImage(simb16_xpm), new xpmImage(simb17_xpm), new xpmImage(simb18_xpm), new xpmImage(simb19_xpm), new xpmImage(simb20_xpm), new xpmImage(simb21_xpm), new xpmImage(simb22_xpm), new xpmImage(simb23_xpm), new xpmImage(simb24_xpm), new xpmImage(simb25_xpm), new xpmImage(simb26_xpm), new xpmImage(simb27_xpm), new xpmImage(simb28_xpm), new xpmImage(simb29_xpm), new xpmImage(simb30_xpm), new xpmImage(simb31_xpm)};

enum{
	FINESTRA_LARGH = 800,
	FINESTRA_ALT = 700,
	MARGINE_X = 10,
	MARGINE_Y = 10,
	INPUT_LARGH = 300,
	INPUT_ALT = 35,
	VERT_SPAZ = 5,
	HORIZ_SPAZ = 5,
	MAX_RIGHE = 20,
	BUTTON_LARGH = 50,
	BUTTON_ALT = 20,
	CHOICE_LARGH = 80,
	CHOICE_ALT = 20,
	CHOICE_X = 50,
	CHECK_LARGH = 80,
	CHECK_ALT = 20,
	SIMBOL_LARGH = 40,
	SIMBOL_ALT = 40,
	NUM_CHAR_PIC = 17,
	NUM_CHAR_MED = 8,
	NUM_CHAR_GRAN = 4,
	TEXT_SIZE_PIC = 15,
	TEXT_SIZE_MED = 19,
	TEXT_SIZE_GRAN = 30,
	MARGINE_SX = 0,
	MARGINE_UP = 0,
	SPAZIATURA_PIC = 10,
	SPAZIATURA_MED = 20,
	SPAZIATURA_GRAN = 37,
	SPAZIATURA_RIGA = 10,
	SPAZIATURA_SIMBOL = 4,
	LUNGH_RIGA = 102,
	SPESS_RIGA = 2
};
int MAX_ALT;	//viene messa la maggiore frà INPUT_ALT, BUTTON_ALT, CHOICE_ALT e SIMBOL_ALT
	


static void exit_callback(Widget *, void *) {
	exit(0);
}

class LimInput : public Input {
	int limite;
	bool limitato;
	
	public:
	LimInput(int x, int y, int largh, int lungh, const char * label=0) : Input(x, y, largh, lungh, label) {
		limite = 0;
		limitato = false;
	}
	
	~LimInput() {}	
	
	int handle(int evento){
		int ret = Input::handle(evento);	//chiama handler superiore
		if((evento == KEY) && (limitato)){					//se premuto un tasto e se è limitato
			if(size() > limite){			//se troppi caratteri
				cut(-1);
			}
			return 1;
		}
		return ret;
	}
	
	void textsize(float a){
		Input::textsize(a);
		redraw();
	}		
	
	void setLimite(int lim){
		if(lim >= 0)
			limite = lim;
		else
			limite = 0;
		cut(limite, size());	//toglie caratteri in più
		redraw();
		return;
	}
	void attiva(){
		limitato = true;
	}
	void disattiva(){
		limitato = false;
	}
};

class LimIntInput : public IntInput {
	int limite;
	
	public:
	LimIntInput(int x, int y, int largh, int lungh, const char * label=0) : IntInput(x, y, largh, lungh, label) {
		limite = 4;
	}
	
	~LimIntInput() {}	
	
	int handle(int evento){
		int ret = Input::handle(evento);	//chiama handler superiore
		if(evento == KEY){					//se premuto un tasto e se è limitato
			if(size() > limite){			//se troppi caratteri
				cut(-1);
			}
			return 1;
		}
		return ret;
	}
};

class StyChoice : public Choice {

	public:
	StyChoice(int x, int y, int largh, int lungh, const char * label=0) : Choice(x, y, largh, lungh, label) {
		add("piccolo");
		add("medio");
		add("grande");
	}
	~StyChoice(){}
};

class OggettoRiga : public Widget {
	public:
	OggettoRiga(int x, int y, int largh, int lungh) : Widget(x, y, largh, lungh, "------------------------------------------") {
		//box(FLAT_BOX);
		//color(GRAY75);
	}
	~OggettoRiga() {}
	void draw(){
		draw_label();
	}
};

class Simbolo : public PopupMenu {
	char corrispondenza[21];
	
	public:
	Simbolo(int x, int y, int largh, int lungh, const char * label=0) : PopupMenu(x, y, largh, lungh, 0){
		value(0);	//altrimenti = -1 alla creazione
		add("nessuno");
		add("lavaggio in acqua a 30°");
		add("lavaggio in acqua a 40°");
		add("lavaggio in acqua a 60°");
		add("lavaggio in acqua a 90°");
		add("lavaggio in acqua a 95°");
		add("non lavare in acqua");
		add("lavaggio a mano");
		add("ferro da stiro a 100°");
		add("ferro da stiro a 150°");
		add("ferro da stiro a 200°");
		add("non stirare");
		add("candeggio consentito");
		add("non candeggiare");
		add("lavaggio a secco con tutti i solventi");
		add("lavaggio a secco con percloroetilene");
		add("lavaggio a secco con idrocarburi");
		add("non lavare a secco");
		add("asciugatura in tamburo");
		add("non asciugare in tamburo");
		
		sprintf(corrispondenza, "xABCDEFGHIJKLMNOPQRS");
	}
	~Simbolo(){}
		
	int handle(int evento){
		int ret = PopupMenu::handle(evento);
		int v;
		
		if(evento == PUSH){	//se cliccato
			v = value();	//valore selezionato
			if(v == 0)	//se nessuno (primo)
				image(0);	//toglie immagine
			else
				image(simboli[v-1]);	//altrimenti mette quella giusta

			redraw();		//ridisegna
		}		
		return ret;
	}
	
	char getChar(){
		return corrispondenza[value()];
	}
	void setChar(char c){
		char str[2];
		int v;

		str[0] = c;
		str[1] = '\0';
		v = strcspn(corrispondenza, str);
		value(v);
		if(v == 0)	//se nessuno (primo)
			image(0);	//toglie immagine
		else
			image(simboli[v-1]);	//altrimenti mette quella giusta

		redraw();		//ridisegna
	}
};

class Riga : public Group{	
	inline void del_callback_i() {
		if(!((prec == NULL) && (succ->succ ==NULL))){	//se non unico elemento
			if(prec != NULL)	//se non è primo elemento
				prec->succ = succ;	//imposta il successivo del precedente al prossimo
			//if(succ != NULL){	//se non ultimo
			succ->spostaSu();	//sposta ricorsivamente le righe successive
			succ->prec = prec;	//imposta il precedente del successivo al precedente
			//}
			delete this;	//cancella la riga
		}
	}
	static void del_callback(Widget*, void* v) {
		((Riga*)v)->del_callback_i();
	}

	inline void ins_callback_i() {
		Riga *appo = new Riga(x(), y());	//crea nuova riga nella posizione dov'era questa
		
		spostaGiu();	//sposta ricorsivamente (compresa questa) le righe successive
		appo->prec = prec;
		appo->succ = this;	//aggiorna puntatori nuova riga
		if(prec != NULL)
			prec->succ = appo;	//se esiste aggiorna puntatore del precedente
		prec = appo;	//aggiorna puntatore a precedente
		parent()->add(appo);	//aggiunge la riga
	}	
	static void ins_callback(Widget*, void* v) {
		((Riga*)v)->ins_callback_i();
	}

	inline void cho_callback_i(StyChoice *w) {
		int v = w->value();	//valore del contenuto

		switch(v){
			case 0:
				if(!space->state())	//se spaziatura dinamica disattivata
					input->setLimite(NUM_CHAR_PIC);	//modifica limite caratteri
				input->textsize(TEXT_SIZE_PIC);
				break;
			case 1:
				if(!space->state())
					input->setLimite(NUM_CHAR_MED);
				input->textsize(TEXT_SIZE_MED);
				break;
			case 2:
				if(!space->state())
					input->setLimite(NUM_CHAR_GRAN);
				input->textsize(TEXT_SIZE_GRAN);
				break;
		}
	}
	static void cho_callback(Widget* w, void* v) {
		((Riga*)v)->cho_callback_i((StyChoice*)w);
	}
	
	inline void sel_callback_i(Button* w) {
		if(riga->visible()){	//se riga di già
			riga->hide();		//la nasconde
			simb1->set_visible();
			simb2->set_visible();
			simb3->set_visible();
			w->label("Simboli");	//reimposta label
		}else if(simb1->visible()){	//se modalità simboli
			simb1->hide();
			simb2->hide();
			simb3->hide();
			
			input->set_visible();	//fa vedere testo
			choice->set_visible();
			space->set_visible();
			w->label("Testo");	//reimposta label
		}else{
			input->hide();	//nasconde il testo
			choice->hide();
			space->hide();
			riga->set_visible();		//fa vedere riga
			w->label("Riga");	//reimposta label
		}
	}
	static void sel_callback(Widget* w, void* v) {
		((Riga*)v)->sel_callback_i((Button*)w);
	}

	inline void spa_callback_i(CheckButton* w) {
		if(w->value()){	//se è stato attivato (spaziatura dinamica)
			input->disattiva();	//disattiva limitazione
			//alert("ATTENZIONE!\nNon è implementato il controllo sulla dimensione del testo in modalità spaziatura dinamica");
		}else{		//altrimenti se disattivato
			input->attiva();
			switch(choice->value()){	//imposta i limiti massimi per la spaziatura fissa
				case 0:
					input->setLimite(NUM_CHAR_PIC);
					break;
				case 1:
					input->setLimite(NUM_CHAR_MED);
					break;
				case 2:
					input->setLimite(NUM_CHAR_GRAN);
					break;
			}
		}
	}
	static void spa_callback(Widget* w, void* v) {
		((Riga*)v)->spa_callback_i((CheckButton*)w);
	}

	
	public:
		LimInput *input;
		OggettoRiga *riga;
		Simbolo *simb1;
		Simbolo *simb2;
		Simbolo *simb3;
		Button *del;
		Button *ins;
		StyChoice *choice;
		Button *select;
		CheckButton *space;
		
		Riga *succ;
		Riga *prec;

		Riga(int x, int y) :
			Group(x, y, MARGINE_X+INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+CHOICE_X+CHOICE_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+CHOICE_X+CHOICE_LARGH, MAX_ALT, 0, true /*auto-begin() */)
		{
			input = new LimInput(0,0,INPUT_LARGH,INPUT_ALT);
			riga = new OggettoRiga(0,0,INPUT_LARGH,INPUT_ALT);
			simb1 = new Simbolo((INPUT_LARGH - 3*SIMBOL_LARGH)/6, 0, SIMBOL_LARGH, SIMBOL_ALT);
			simb2 = new Simbolo((INPUT_LARGH-SIMBOL_LARGH)/2, 0, SIMBOL_LARGH, SIMBOL_ALT);
			simb3 = new Simbolo((5*INPUT_LARGH - 3*SIMBOL_LARGH)/6, 0, SIMBOL_LARGH, SIMBOL_ALT);
			del = new Button(INPUT_LARGH+HORIZ_SPAZ, 0, BUTTON_LARGH, BUTTON_ALT, "Canc.");
			ins = new Button(INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ, 0, BUTTON_LARGH, BUTTON_ALT, "Ins.");
			choice = new StyChoice(INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+CHOICE_X, 0, CHOICE_LARGH, CHOICE_ALT, "Testo:");
			select = new Button(INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+CHOICE_X+CHOICE_LARGH+HORIZ_SPAZ, 0, BUTTON_LARGH, BUTTON_ALT, "Testo");
			space = new CheckButton(INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+CHOICE_X+CHOICE_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ, 0, CHECK_LARGH, CHECK_ALT, "Spaziatura dinamica");
			
			end();
			prec = NULL;
			succ = NULL;
		
			del->callback(del_callback, this);		//callback (passando punt Riga)
			ins->callback(ins_callback, this);
			choice->callback(cho_callback, this);
			select->callback(sel_callback, this);
			space->callback(spa_callback, this);
			
			riga->hide();	//nasconde riga (label) e i bottoni simboli
			simb1->hide();
			simb2->hide();
			simb3->hide();
			input->attiva();
			input->setLimite(NUM_CHAR_PIC);
			input->textsize(TEXT_SIZE_PIC);
			
		}
		~Riga(){
			delete input;
			delete riga;
			delete simb1;			
			delete simb2;
			delete simb3;
			delete del;
			delete ins;
			delete choice;
			delete select;
			delete space;
		}
				
		void spostaSu(){
			if(succ != NULL)	//se non ultima
				succ->spostaSu();	//sposta la seguente
			y(prec->y());	//prende posizione del precedente (al ritorno)
			//redraw();	//ridisegna al ritorno
		}
		
		void spostaGiu(){
			if (succ != NULL){	//se non ultima riga
				y(succ->y());	//prende posizione della successiva
				succ->spostaGiu();	//sposta la successiva
			}
			else	//se ultima
				move(0, MAX_ALT+VERT_SPAZ);	//sposta in giù
			//redraw();	//ridisegna al ritorno
		}
};

class Dialog : public Window{
	Widget *titolo;
	LimIntInput *numeroCopie;
	Button *ok;
	
	inline void stampaOk_callback_i(){
		make_exec_return(true);
	}
	static void stampaOk_callback(Widget*, void* v) {	//callback quando premuto bottone stampa.
		((Dialog*)v)->stampaOk_callback_i();
	}

	inline void x_callback_i(){
		make_exec_return(false);
	}
	static void x_callback(Widget*, void* v) {	//callback quando premuto bottone stampa.
		((Dialog*)v)->x_callback_i();
	}
	
	public:
		Dialog(int x, int y, int w, int h, const char *l) : Window(x, y, w, h, l, true){
			titolo = new Widget(5, 5, 300, 20, "Inserisci quante etichette vuoi stampare");
			titolo->box(ROUNDED_BOX);
			numeroCopie = new LimIntInput(5,30,50, 20);
			ok = new Button(60, 30, 50, 20, "Ok");
			end();
			callback(x_callback, this);
			ok->callback(stampaOk_callback, this);
		}
		~Dialog(){
			delete titolo;
			delete numeroCopie;
			delete ok;
		}
		
		int getValue(){
			return numeroCopie->ivalue();
		}
};

class Finestra : public Window {
	Riga *ultimaRiga;
	Button *bott_aggiungi;
	Button *bott_stampa;
	Button *bott_salva;
	Button *bott_carica;
	Button *bott_azzera;
	Button *bott_chiudi;
	ScrollGroup *gruppoRighe;
	char *stringa;

	void aggiornaStringa(int quantita){
		int dimensione=0, y=0;
		Riga *scorr;
		char margineSx[5];
		char appo[5];
		
		
		dimensione += 11;	//per il "/C\n", '\0' e "/Wxxxx\n"
		scorr = ultimaRiga;	//parte dall'ultima riga (fittizia)
		while(scorr->prec != NULL){	//finchè ci sono righe
			scorr = scorr->prec;	//passa alla riga
			if(scorr->input->visible())	//se modalità testo
				dimensione += 19+scorr->input->size();	//dimensione per una riga (compreso il '\n' finale)
			else if(scorr->riga->visible())	//se modalità riga
				dimensione += 20;
			else{	//se modalità simboli
				dimensione += 16;
				if(scorr->simb1->value() != 0)		//se primo simbolo non vuoto
					dimensione ++;
				if(scorr->simb2->value() != 0)		//se secondo simbolo non vuoto
					dimensione ++;
				if(scorr->simb3->value() != 0)		//se terzo simbolo non vuoto
					dimensione ++;
			}
		}
		//adesso scorr punta alla prima
		free(stringa);		//elimina precedente stringa
		stringa = (char *)malloc(dimensione*sizeof(char));	//alloca lo spazio necessario
		stringa[0] = '\0';		//inizializza a stringa vuota
		
		sprintf(margineSx, "%04d", MARGINE_SX);	//ricava la stringa con margine
		
		strcat(stringa, "/C\n");
		
		y += MARGINE_UP;
		while(scorr->succ != NULL){	//finchè non arrivato a riga fittizia
			if(scorr->input->visible()){	//se modalità testo
				strcat(stringa, "/E");
				strcat(stringa, margineSx);
				switch(scorr->choice->value()){	//a seconda della dimensione del testo
					case 0:	
						y += SPAZIATURA_PIC;	//aggiorna posizione verticale
						sprintf(appo, "%04d", y);	//ricava la stringa con posizione
						strcat(stringa, appo);		//la scrive
						strcat(stringa, "/F011");
						break;
					case 1:
						y += SPAZIATURA_MED;	//aggiorna posizione verticale
						sprintf(appo, "%04d", y);	//ricava la stringa con posizione
						strcat(stringa, appo);		//la scrive
						strcat(stringa, "/F111");
						break;
					case 2:
						y += SPAZIATURA_GRAN;	//aggiorna posizione verticale
						sprintf(appo, "%04d", y);	//ricava la stringa con posizione
						strcat(stringa, appo);		//la scrive
						strcat(stringa, "/F211");
						break;
				}
				if(scorr->space->value())	//se attivata spaziatura dinamica
					strcat(stringa, "/T1");
				else
					strcat(stringa, "/T0");
				
				strcat(stringa, scorr->input->value());	//inserisce testo
				strcat(stringa, "\n");	//ritorno a capo
			}
			else if(scorr->riga->visible()){	//se modalità riga
				strcat(stringa, "/E");
				strcat(stringa, margineSx);
				y += SPAZIATURA_RIGA;	//aggiorna posizione verticale
				sprintf(appo, "%04d", y);	//ricava la stringa con posizione
				strcat(stringa, appo);		//la scrive
				strcat(stringa, "/L0");
				sprintf(appo, "%04d", LUNGH_RIGA);	//ricava la stringa con lunghezza riga
				strcat(stringa, appo);
				sprintf(appo, "%02d", SPESS_RIGA);	//ricava la stringa con spessore riga
				strcat(stringa, appo);
				strcat(stringa, "\n");
				//strcat(stringa, "/L0006002\n");				
			}
			else{	//se modalità simboli
				strcat(stringa, "/E");
				strcat(stringa, margineSx);
				y += SPAZIATURA_SIMBOL;	//aggiorna posizione verticale
				sprintf(appo, "%04d", y);	//ricava la stringa con posizione
				strcat(stringa, appo);		//la scrive
				strcat(stringa, "/F311");
				if(scorr->simb1->value() != 0){		//se primo simbolo non vuoto
					sprintf(appo, "%c", scorr->simb1->getChar());	//scrive il corrispondente valore
					strcat(stringa, appo);
				}
				if(scorr->simb2->value() != 0){		//se secondo simbolo non vuoto
					sprintf(appo, "%c", scorr->simb2->getChar());	//scrive il corrispondente valore
					strcat(stringa, appo);
				}
				if(scorr->simb3->value() != 0){		//se terzo simbolo non vuoto
					sprintf(appo, "%c", scorr->simb3->getChar());	//scrive il corrispondente valore
					strcat(stringa, appo);
				}
				strcat(stringa, "\n");
			}
			scorr = scorr->succ;	//avanza
		}
		strcat(stringa, "/W");	//comando per scrivere le etichette
		sprintf(appo, "%04d\n", quantita);	//ricava la stringa con quantita
		strcat(stringa, appo);		//la scrive
	}

	inline void aggiungi_callback_i() {	
		Riga *appo = new Riga(ultimaRiga->x(), ultimaRiga->y());	//crea nuova riga
		appo->prec = ultimaRiga->prec;
		appo->succ = ultimaRiga;
		ultimaRiga->prec->succ = appo;	//la inserisce prima di quella fittizia
		ultimaRiga->prec = appo;
		gruppoRighe->add(appo);
		ultimaRiga->move(0, MAX_ALT+VERT_SPAZ);
	}
	static void aggiungi_callback(Widget*, void* v) {	//callback quando premuto bottone aggiungi.
		((Finestra*)v)->aggiungi_callback_i();
	}
	
	inline void stampa_callback_i() {
		int quantita=0;
		CSerial serial;	//controllore della seriale
		
		Dialog *chiediCopie = new Dialog(10, 35, 310, 100, 0);	//dialog per la stampa
		chiediCopie->show();
		
		if(chiediCopie->exec()){	//se premuto ok (aspetta la scelta dell'utente)
			quantita = chiediCopie->getValue();	//prende la quantità scelta
			if(ask("Stampare %d copie?", quantita)){
				aggiornaStringa(quantita);
				
				if (serial.Open(1, 9600)){	//apre la seriale
					serial.SendData(stringa, strlen(stringa));	//manda alla macchina
					serial.Close();
					message("Etichetta inviata alla macchina.");
				}else
					alert("Errore di comunicazione con la seriale.");
			}
		}		
	}
	static void stampa_callback(Widget*, void* v) {	//callback quando premuto bottone stampa.
		((Finestra*)v)->stampa_callback_i();
	}

	inline void salva_callback_i(){
		FILE * file;
		char suffisso[5];
		char * nomeFile;
		char * messaggio;
		char ok[] = "Etichetta salvata con successo in:\n\0";
		char errore[] = "ERRORE, impossibile scrivere il file:\n\0";
		const char * nomeFileConst = file_chooser("SALVA","Etichette (*.eti)","./etichette/");	//prende percorso file
		if((nomeFileConst != NULL) && (strlen(nomeFileConst) >= 4)){	//se non pigiato annulla e se stringa sufficentemente lunga
			strcpy(suffisso, nomeFileConst+(strlen(nomeFileConst)-4));	//si ricava il suffisso
			if(strcmp(suffisso, ".eti") != 0){	//se non aggiunto suffisso
				nomeFile = (char*)malloc((strlen(nomeFileConst)+5)* sizeof(char));	//alloca spazio per la nuova stringa
				strcpy(nomeFile, nomeFileConst);	//copia stringa attuale
				strcat(nomeFile, ".eti");	//aggiunge suffisso
			}else{	//se gia aggiunto suffisso
				nomeFile = (char*)malloc((strlen(nomeFileConst)+1)* sizeof(char));	//alloca spazio per la nuova stringa
				strcpy(nomeFile, nomeFileConst);	//copia stringa attuale
			}
			if((fopen(nomeFile, "r") == NULL) || (ask("Attenzione, il file esiste già!\ndesideri cancellarlo?") == 1)){	//se file non esiste gia, oppure se esiste, si da il consenso a sovrascrivere
				if(file = fopen(nomeFile,"w")){ 	//apre file
					aggiornaStringa(1);	//aggiorna stringa etichetta
					fprintf(file, stringa);	//scrive su file
					fclose(file);	//chiude file

					messaggio = (char*)malloc((strlen(nomeFile)+strlen(ok)+1)* sizeof(char));	//alloca spazio per la nuova stringa
					strcpy(messaggio, ok);
					strcat(messaggio, nomeFile);
					message(messaggio);
				}else{
					messaggio = (char*)malloc((strlen(nomeFile)+strlen(errore)+1)* sizeof(char));	//alloca spazio per la nuova stringa
					strcpy(messaggio, errore);
					strcat(messaggio, nomeFile);
					alert(messaggio);
				}
				free(messaggio);
			}
			free(nomeFile);	//libera memoria allocata per la stringa
		}
	}
	static void salva_callback(Widget*, void* v) {	//callback quando premuto bottone stampa.
		((Finestra*)v)->salva_callback_i();
	}
	
	inline void carica_callback_i(){
		Riga * scorr;
		int i;
		bool modalitaSimboli;
		FILE *file;
		char car;
		char strinCar[2];
		strinCar[1] = '\0';
		const char * nomeFileConst;
		if(ask("Attenzione, l'etichetta corrente verrà cancellata.\nProseguire con l'operazione?") == 1){
			nomeFileConst = file_chooser("CARICA","Etichette (*.eti)","./etichette/");	//prende percorso file
			if(file = fopen(nomeFileConst, "r")){	//se può aprire il file
				scorr = ultimaRiga->prec;	//prendo l'ultima
				while(scorr->prec != NULL)	//finché ci sono righe prima
					scorr->prec->del->do_callback();	//cancella la precedente

				car = fgetc(file);	//acquisisce il primo carattere
				while(!feof(file)){	//finchè non è finito il file
					while((car != '/') && (!feof(file))){	//finché non trovo un / e il file non è finito
						car = fgetc(file);	//avanza
						
					}
					if(!feof(file)){	//se non è finito il file
						car = fgetc(file);
						if(car == 'F'){	//se prox F
							bott_aggiungi->do_callback();	//aggiunge riga
							modalitaSimboli = false;
							car = fgetc(file);
							switch(car){
								//case '0':	ultimaRiga->prec->choice->value(0); break;	//gia di default
								case '1':	ultimaRiga->prec->choice->value(1); break;	//imposta la choice dell'ultima riga
								case '2':	ultimaRiga->prec->choice->value(2); break;
								case '3':	
									ultimaRiga->prec->select->do_callback();	//pigia du volte il bottone per i simboli
									ultimaRiga->prec->select->do_callback();
									modalitaSimboli = true;
									break;
							}
							ultimaRiga->prec->choice->do_callback();
							fgetc(file);
							fgetc(file);	//salta i moltiplicatori
							if(!modalitaSimboli){	//se non modalita simboli
								fgetc(file);	//salta /T
								fgetc(file);
								car = fgetc(file);
								if(car == '1')	//se dinamico
									ultimaRiga->prec->space->value(true);
									ultimaRiga->prec->space->do_callback();
							}

							i = 1;
							car = fgetc(file);
							while(car != '\n'){	//finchè non finisce riga
								if(!modalitaSimboli){	//se non modalita simboli
									strinCar[0] = car;
									ultimaRiga->prec->input->insert(strinCar);	//aggiunge carattere
								}else{	//se modalita simboli
									switch(i){
										case 1: ultimaRiga->prec->simb1->setChar(car); break;
										case 2: ultimaRiga->prec->simb2->setChar(car); break;
										case 3: ultimaRiga->prec->simb3->setChar(car); break;
									}
									i++;
								}
								car = fgetc(file);
							}
						}else if(car == 'L'){
							bott_aggiungi->do_callback();	//aggiunge riga
							ultimaRiga->prec->select->do_callback();
						}
					}
				}
				fclose(file);

				scorr = ultimaRiga;
				while(scorr->prec != NULL)	//finché ci sono righe
					scorr = scorr->prec;	//ci vado
				scorr->del->do_callback();	//cancello la prima (che era rimasta dall'inizio)
			}
		}
	}
	static void carica_callback(Widget*, void* v) {	//callback quando premuto bottone stampa.
		((Finestra*)v)->carica_callback_i();
	}
	
	inline void azzera_callback_i(){
		Riga *scorr;
		if(ask("Cancellare l'etichetta corrente?") == 1){	//se si da il consenso
			bott_aggiungi->do_callback();	//aggiungo una riga
			scorr = ultimaRiga->prec;	//prendo l'ultima
			while(scorr->prec != NULL)	//finché ci sono righe prima
				scorr->prec->del->do_callback();	//cancella la precedente
		}
	}
	static void azzera_callback(Widget*, void* v) {	//callback quando premuto bottone azzera.
		((Finestra*)v)->azzera_callback_i();
	}

	inline void finestra_callback_i(){
		if(ask("Attenzione, tutte le modifiche non salvate andranno perse.\nChiudere l'applicazione?"))
			destroy();
	}
	static void finestra_callback(Widget*, void* v){
		((Finestra*)v)->finestra_callback_i();
	}
	
	public:

	Finestra(const char* label=0) : Window(10,30,FINESTRA_LARGH,FINESTRA_ALT,label,true) {
		
		bott_aggiungi = new Button(MARGINE_X, MARGINE_Y, INPUT_LARGH, BUTTON_ALT, "Aggiungi riga");	//e il bottone
		bott_aggiungi->callback(aggiungi_callback,this);
		
		bott_stampa = new Button(MARGINE_X+INPUT_LARGH+HORIZ_SPAZ, MARGINE_Y, BUTTON_LARGH, BUTTON_ALT, "Stampa");
		bott_stampa->callback(stampa_callback, this);

		bott_salva = new Button(MARGINE_X+INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+3*HORIZ_SPAZ, MARGINE_Y, BUTTON_LARGH, BUTTON_ALT, "Salva");
		bott_salva->callback(salva_callback, this);

		bott_carica = new Button(MARGINE_X+INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+3*HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ, MARGINE_Y, BUTTON_LARGH, BUTTON_ALT, "Carica");
		bott_carica->callback(carica_callback, this);

		bott_azzera = new Button(MARGINE_X+INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+3*HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ, MARGINE_Y, BUTTON_LARGH*2, BUTTON_ALT, "AZZERA TUTTO");
		bott_azzera->callback(azzera_callback, this);

		bott_chiudi = new Button(MARGINE_X+INPUT_LARGH+HORIZ_SPAZ+BUTTON_LARGH+3*HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+BUTTON_LARGH+HORIZ_SPAZ+BUTTON_LARGH*2+HORIZ_SPAZ, MARGINE_Y, BUTTON_LARGH, BUTTON_ALT, "Chiudi");
		bott_chiudi->callback(finestra_callback, this);
		
		gruppoRighe = new ScrollGroup(0, MARGINE_Y+BUTTON_ALT+VERT_SPAZ*2, FINESTRA_LARGH, FINESTRA_ALT-(MARGINE_Y+BUTTON_ALT+VERT_SPAZ*2));

		gruppoRighe->begin();
		ultimaRiga = new Riga(MARGINE_X, MARGINE_Y);
		ultimaRiga->succ = new Riga(MARGINE_X, MARGINE_Y+MAX_ALT+VERT_SPAZ);	//crea riga fittizia
		ultimaRiga->succ->prec = ultimaRiga;	//aggiorna puntatore a prec
		ultimaRiga = ultimaRiga->succ;
		ultimaRiga->hide();

		gruppoRighe->end();
		end();
		callback(finestra_callback, this);
	
		//fullscreen();
		stringa = (char *)malloc(sizeof(char));		//inizializza stringa (a stringa vuota)
		stringa[0] = '\0';
	}

	~Finestra() {
		
		Riga *appo;
		while(ultimaRiga != NULL){	//finchè ci sono righe
			appo = ultimaRiga;
			ultimaRiga = ultimaRiga->prec;	//avanza (o meglio retrocede)
			delete(appo);	//libera riga
		}
		delete(gruppoRighe);
		delete(bott_aggiungi);
		delete(bott_stampa);
		delete(bott_salva);
		delete(bott_carica);
		delete(bott_azzera);
		delete(bott_chiudi);
		free(stringa);
	}

};

int main(int argc, char ** argv) {
	MAX_ALT = INPUT_ALT;		//mette in MAX_ALT l'altezza massima
	if(BUTTON_ALT > MAX_ALT)
		MAX_ALT = BUTTON_ALT;
	if(CHOICE_ALT > MAX_ALT)
		MAX_ALT = CHOICE_ALT;
	if(CHECK_ALT > MAX_ALT)
		MAX_ALT = CHECK_ALT;
	if(SIMBOL_ALT > MAX_ALT)
		MAX_ALT = SIMBOL_ALT;
		
	Finestra window1("Etichettatrice 1.0");
	window1.show(argc,argv);
	return run();
}
