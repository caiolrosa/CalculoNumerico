PROGRAM newton
IMPLICIT NONE

    REAL :: input, root, errAprox
    INTEGER :: count, maxIterations
    CHARACTER(len = 32) :: arg

    CALL get_command_argument(1, arg)
    READ(arg,*) input
    IF (input < 0) THEN
        PRINT *, "Input must be greater then 0"
        STOP 1
    END IF

    count = 0
    maxIterations = 10000
    errAprox = 1E-6
    root = 1

    DO WHILE (ABS(root ** 2 - input) > errAprox .AND. count < maxIterations)
        root = ((input / root) + root) / 2
        count = count + 1
    END DO

    PRINT *, root

END PROGRAM Newton