#define MOTOR_PIN 3
#define ENTRADA A0
#define PERIOD 4096

void setup()
{
    pinMode(MOTOR_PIN, OUTPUT);
	pinMode(ENTRADA, INPUT);

    digitalWrite(MOTOR_PIN, LOW);
}

void loop() {
	float duty = analogRead(ENTRADA) / 1023.0f;

	static long elapsedTime = micros();
	if (micros() - elapsedTime < duty * PERIOD)
	{
		digitalWrite(MOTOR_PIN, HIGH);
	}
	else if (micros() - elapsedTime > PERIOD)
	{
		elapsedTime = micros();
	}
	else
	{
		digitalWrite(MOTOR_PIN, LOW);
	}

	// Serial.print("Duty: "); Serial.println(duty);
	// Serial.print("Duty * PERIOD: "); Serial.println(duty * PERIOD);
}