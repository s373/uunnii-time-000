/*
 *  MiniChronos.h
 *  TemporaryBabel2D_000
 *
 *  Created by André Sier on 20130327.
 *  Copyright 2010 s373.net/x. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"


class MiniChronos {

public:

	MiniChronos(){}
	~MiniChronos(){}

	void setup( bool resethour = true) {
		currentYearIni = UnixToS373Years(ofGetUnixTime());
		currentYear = UnixToS373Years(ofGetUnixTime());
		currentYearEllapsed = currentYear - currentYearIni;
		font.loadFont("spincycle_3d_tt.ttf",21);
		fonts.loadFont("spincycle_3d_tt.ttf",16);

		cbegin = ofGetElapsedTimef();
		cellapsed = ofGetElapsedTimef();
		cellapsedlevel = cellapsed-cbegin;



		secondsThen = ofGetElapsedTimef()+1;
		drawStringUunniiTtiimmee = "";
		drawStringUtc = "";

		quit = false;
		blink = 0; colorstate = true;

	}


	void update( ) {

		if(ofGetMousePressed()){
			ofSetFrameRate(120);
			secondsThen=0.0f;
		}else{
			ofSetFrameRate(1);
		}

		if(ofGetElapsedTimef()>secondsThen){
			secondsThen = ofGetElapsedTimef() + 0.15;
			currentYear = UnixToS373Years(ofGetUnixTime());
			currentYearEllapsed = currentYear - currentYearIni;
			// drawString = ofToString(currentYear,20);
			drawStringUunniiTtiimmee = ofToString(currentYear,12);
			drawStringUtc = getutc();
		}
	}

	void draw(){
		ofEnableAlphaBlending();
		ofSetColor(255,70);
		fonts.drawString("uunniittiimmee / utc", 21, 37);

		ofSetColor(255,170);
		font.drawString(drawStringUunniiTtiimmee, 10, 25);
		font.drawString(drawStringUtc, 16, 52);
	}

	string getutc(){
		char utc[18]={'1','9',':','2','1',':','2','1',' ','2','0','1','0','0','9','2','1'};
		int hours = ofGetHours();
		int minutes = ofGetMinutes();
		int seconds = ofGetSeconds();
		int year = ofGetYear();
		int month = ofGetMonth();
		int day = ofGetDay();
		sprintf(utc, "%02i:%02i:%02i %04i%02i%02i" , hours,minutes,seconds,year,month,day);
		return ofToString(utc);
	}


private:
	double		currentYear;
	double		currentYearIni;
	double		currentYearEllapsed;
	double		currentYearMax;
	float		cyear, cyearini,cyearmax;
	float		cellapsed, cellapsedmax, cbegin, cellapsedlevel;
	float		secondsThen;
	string		drawStringUunniiTtiimmee;
	string		drawStringUtc;
	bool		quit;
	ofTrueTypeFont font, fonts;
	int			blink;
	bool		colorstate;

	double UnixToS373Years(unsigned int unixTime){

		double s373Years = (double) unixTime / 31536000.0; // dividir pelo #segundos de um ano

		s373Years += 1970.0; // adicionar 1970

		return s373Years;


		/*
					 1 minuto = 60 segundos
					 1 hora = 3600 segundos
					 1 dia = 86400 segundos

				1 semana = 604800 segundos
				30 dias = 2592000 segundos
				1 ano  = 31536000 segundos

		 */



		/*
				 unix time example

				 1365723433

				 /

				 num segundos num ano 31536000

				 =

				 43.306805968

				 + 1970

				 = 2013.306805968

		 */


	}


	unsigned int S373YearsToUnix(double uunniiTime){
		//
		return -1;
	}


};
