-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Verificar a descrição do crime, tendo informação somente da data e lugar
SELECT description FROM crime_scene_reports
    WHERE month = 7 AND day = 28
    AND year = 2020 AND street = "Chamberlin Street";
    /* Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
    Interviews were conducted today with three witnesses who were present at the time —
    each of their interview transcripts mentions the courthouse.*/

-- Analisar as entrevistas realizadas com as 3 testemunhas do crime
SELECT name, transcript FROM interviews
    WHERE year = 2020 AND month = 7 AND day = 28
    AND transcript LIKE "%courthouse%";
    /*
    Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the
    courthouse parking lot and drive away. If you have security footage from the courthouse
    parking lot, you might want to look for cars that left the parking lot in that time frame.

    Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning,
    before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief
    there withdrawing some money.

    Raymond | As the thief was leaving the courthouse, they called someone who talked to them for
    less than a minute. In the call, I heard the thief say that they were planning to take the
    earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end
    of the phone to purchase the flight ticket.
    */

-- Saber quais carros teve atividade de saída após o roubo
SELECT name FROM people
    JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
    WHERE courthouse_security_logs.year = 2020
    AND courthouse_security_logs.month = 7
    AND courthouse_security_logs.day = 28
    AND courthouse_security_logs.hour = 10
    AND courthouse_security_logs.minute > 15
    AND courthouse_security_logs.minute < 25
    AND courthouse_security_logs.activity = "exit"
        ORDER BY people.name;
    -- Suspeitos: Amber, Danielle, Elizabeth, Ernest, Evelyn, Patrick, Roger, Russell

-- Pegar informações das contas que fizeram saques na agência Fifer Street no dia do roubo
SELECT name FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    WHERE atm_transactions.year = 2020
    AND atm_transactions.month = 7 AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Fifer Street"
    AND atm_transactions.transaction_type = "withdraw"
        ORDER BY people.name;
    -- Suspeitos: Bobby, Danielle, Elizabeth, Ernest, Madison, Roy, Russell, Victoria

-- Listar as ligações feitas no dia 28/07/2020 que duraram menos de 60 segundos
SELECT name FROM people
    WHERE phone_number IN (SELECT caller FROM phone_calls
    WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
    ORDER BY name;
    -- Suspeitos: Bobby, Ernest, Evelyn, Kimberly, Madison, Roger, Russell, Victoria

-- Listar os vôos que partiram de Fiftyville no dia 29/07/2020 ordenado por hora e minuto
SELECT airports.full_name, flights.hour, flights.minute FROM airports
    JOIN flights ON airports.id = flights.destination_airport_id
    WHERE flights.origin_airport_id = (SELECT id FROM airports
    WHERE full_name LIKE "%Fiftyville%")
    AND year = 2020 AND month = 7 AND day = 29
    ORDER BY flights.hour, flights.minute LIMIT 1;
    -- Aeroporto: Heathrow Airport | Horário: 8:20h

-- Listar os passaportes dos passageiros do vôo acima
SELECT name FROM people
    JOIN passengers ON people.passport_number = passengers.passport_number
    JOIN flights ON passengers.flight_id = flights.id
    WHERE year = 2020 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20
    AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
    ORDER BY people.name;
    -- Suspeitos: Bobby, Danielle, Doris, Edward, Ernest, Evelyn, Madison, Roger

-- Fazendo INTERSECT para saber o nome comum em todas as pesquisas
SELECT name FROM people
    JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.license_plate
    WHERE courthouse_security_logs.year = 2020
    AND courthouse_security_logs.month = 7
    AND courthouse_security_logs.day = 28
    AND courthouse_security_logs.hour = 10
    AND courthouse_security_logs.minute > 15
    AND courthouse_security_logs.minute < 25
    AND courthouse_security_logs.activity = "exit"
INTERSECT
SELECT name FROM people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
    WHERE atm_transactions.year = 2020
    AND atm_transactions.month = 7 AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Fifer Street"
    AND atm_transactions.transaction_type = "withdraw"
INTERSECT
SELECT name FROM people
    WHERE phone_number IN (SELECT caller FROM phone_calls
    WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
INTERSECT
SELECT name FROM people
    JOIN passengers ON people.passport_number = passengers.passport_number
    JOIN flights ON passengers.flight_id = flights.id
    WHERE year = 2020 AND month = 7 AND day = 29 AND hour = 8 AND minute = 20
    AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville")
    ORDER BY people.name;
    -- Suspeito: Ernest

-- Saber quem foi o cúmplice
SELECT name FROM people
    WHERE phone_number IN (SELECT receiver FROM phone_calls
        WHERE year = 2020 AND month = 7 AND day = 28
        AND duration < 60 AND caller IN (SELECT phone_number
        FROM people WHERE name = "Ernest"));
    -- Cúmplice: Berthold

SELECT city FROM airports WHERE full_name = "Heathrow Airport";
-- Destino: London