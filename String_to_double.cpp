void String_to_double(){
	string STOD_input;
	short int STOD_decimal_counter = 0;
	short int STOD_negative_counter = 0;
	short int STOD_array_counter = 0;
	double STOD_double = 0;
	double STOD_result = 0;
	while( STOD_array_counter < STOD_input.length() ){
		if( STOD_input[STOD_array_counter] == '.' ){
			STOD_decimal_counter = STOD_decimal_counter + 1;
			STOD_decimal_point = STOD_array_counter;
		}
		if( STOD_input[STOD_array_counter] == '-'){
			STOD_negative_counter = STOD_negative_counter + 1;
		}
		STOD_array_counter++;
	}
	if( STOD_decimal_counter > 1 || STOD_negative_counter > 1){
		cout << "SYNTAX ERROR" << endl;
	} else {
		STOD_array_counter = 0;
		//Calculating with a decimal and positive
		if ( STOD_decimal_counter == 1 && STOD_negative_counter == 0){
			while( STOD_array_counter < STOD_decimal_point ){
				STOD_double = STOD_decimal_point - STOD_array_counter - 1;
				STOD_result = STOD_result + ((STOD_input[STOD_array_counter] - '0') * (pow(10, STOD_double)));
				STOD_array_counter++;
			}
			STOD_array_counter++;
			//We subtract one to account for the decimal point in the string
			while ( STOD_array_counter < STOD_input.length() ){
				STOD_double = -(STOD_array_counter - STOD_decimal_point);
				STOD_result = STOD_result + ((STOD_input[STOD_array_counter] - '0') * (pow(10, STOD_double)));
				STOD_array_counter++;
			}	
		}
		//Calculating with a decimal and negative
		if (STOD_decimal_counter == 1 && STOD_negative_counter == 1){
				STOD_input.erase(0, 1);
				while( STOD_array_counter < STOD_decimal_point ){
				STOD_double = STOD_decimal_point - STOD_array_counter - 1;
				STOD_result = STOD_result + ((STOD_input[STOD_array_counter] - '0') * (pow(10, STOD_double)));
				STOD_array_counter++;
			}
			STOD_array_counter++;
			//We subtract one to account for the decimal point in the string
			while ( STOD_array_counter < STOD_input.length() ){
				STOD_double = -(STOD_array_counter - STOD_decimal_point);
				STOD_result = STOD_result + ((STOD_input[STOD_array_counter] - '0') * (pow(10, STOD_double)));
				STOD_array_counter++;
			}	
			STOD_result = -STOD_result;
		}
		//Calculating with no decimal and positive
		if( STOD_decimal_counter == 0 && STOD_negative_counter == 0){
			while( STOD_array_counter < STOD_input.length() ){
				STOD_double = STOD_input.length() - STOD_array_counter - 1;
				STOD_result = STOD_result + ((STOD_input[STOD_array_counter] - '0') * (pow(10, STOD_double)));
				STOD_array_counter++;
			}
		} 
		//Calculating with no decimal and negative
		//This simply removes the negative sign from the string and multiplies by -1 
		if( STOD_decimal_counter == 0 && STOD_negative_counter == 1){
			STOD_input.erase(0, 1);
				while( STOD_array_counter < STOD_input.length() ){
					STOD_double = STOD_input.length() - STOD_array_counter - 1;
					STOD_result = STOD_result + (-((STOD_input[STOD_array_counter] - '0') * (pow(10, STOD_double))));
					STOD_array_counter++;
				}
		}
	}
}
