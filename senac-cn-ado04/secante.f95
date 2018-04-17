PROGRAM secante
    IMPLICIT NONE

    INTEGER :: maxIteration = 1000, counter
    DOUBLE PRECISION :: input, ini, sec, root, errorValue = 1E-6
    CHARACTER(len = 32) :: arg
    CALL get_command_argument(1, arg)
    READ (arg, *) input
    
    counter = 0
    ini = input
    sec = input - 1.0
    
    DO WHILE (counter < maxIteration)
        root = (ini * sec + input) / (ini + sec)
        IF (abs(root - sec) < errorValue .OR. root ** 2 == input) THEN
            PRINT *, REAL(root)
            EXIT
        END IF
        ini = sec
        sec = root
        counter = counter + 1
    END DO

END PROGRAM
