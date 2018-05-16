PROGRAM bhaskara

    IMPLICIT NONE

    CHARACTER(len = 32) :: arg, xr1, xr2, xci
    DOUBLE PRECISION :: inputs(0:2), delta
    INTEGER :: i
	
    DO i = 1, 3 
        CALL get_command_argument(i, arg)
        READ(arg, *) inputs(i - 1)
    END DO

    IF (inputs(0) == 0 .AND. inputs(1) == 0 .AND. inputs(2) == 0) THEN
        PRINT *, "Not a function"
        STOP 1
	END IF

    delta = CalculaDelta(inputs(0), inputs(1), inputs(2))

    IF(delta >= 0.0) THEN
        WRITE(xr1, '(F0.16)') ((-inputs(1) + (delta ** 0.5)) / (2 * inputs(0)))
        WRITE(xr2, '(F0.16)') ((-inputs(1) - (delta ** 0.5)) / (2 * inputs(0)))
        WRITE(*, '(A,A)') 'r1 = ', strReplace(xr1)
        WRITE(*, '(A,A)') 'r2 = ', strReplace(xr2)
    ELSE
        WRITE(xr1, '(F0.16)') (-inputs(1) / (2 * inputs(0)))
        WRITE(xci, '(F0.16)') ((-delta ** 0.5) / (2 * inputs(0)))
        WRITE(*, '(A,A,A,A,A)') 'r1 = ', trim(strReplace(xr1)), ' + ', trim(strReplace(xci)), 'i'
        WRITE(*, '(A,A,A,A,A)') 'r2 = ', trim(strReplace(xr1)), ' - ', trim(strReplace(xci)), 'i'
    END IF
    
    CONTAINS !implementa metodos
    FUNCTION strReplace(str) RESULT(output)
        CHARACTER(len = 32), intent(in) :: str
        CHARACTER(len = 32) :: output
	
        IF(str(1:1) == ".") THEN
            output = "0" // trim(str)
        ELSE IF(str(1:2) == "-.") THEN
            output = "-0" // trim(str(3:))
        ELSE
            output = str
        END IF 
    END FUNCTION
    
    FUNCTION CalculaDelta(a, b, c) RESULT(output)
        DOUBLE PRECISION, intent(in) :: a, b, c
        DOUBLE PRECISION :: output
	
        output = (b ** 2) - (4 * a * c)
    END FUNCTION

END PROGRAM
