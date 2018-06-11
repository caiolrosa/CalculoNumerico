SUBROUTINE get_ranking(matrix)
	INTEGER :: matrixSize, i
	DOUBLE PRECISION :: matrixSizeDBL, threshold, temp, m
	DOUBLE PRECISION, DIMENSION(:,:) :: matrix
	DOUBLE PRECISION, DIMENSION(:,:), ALLOCATABLE :: S, ranking
	
	statusCode = 123
	threshold = 1E-5
	m = 0.15

	! Verifica se a matriz é quadrada
	matrixSizeDBL = SQRT(REAL(SIZE(matrix)))
	matrixSize = INT(matrixSizeDBL)
	IF ((matrixSizeDBL * matrixSizeDBL) /= (INT(matrixSizeDBL) * INT(matrixSizeDBL))) THEN
		PRINT *, "ERRO: Matriz de entrada não é quadrada"
		STOP 1
	END IF 

	ALLOCATE(S(matrixSize, 1))
	ALLOCATE(ranking(matrixSize, 1))
	
	DO i = 1, matrixSize
		S(i,1) = (1.0 / matrixSize) 
		ranking(i,1) = 1.0 / matrixSize
	END DO

	DO i = 1, matrixSize
		DO j = 1, matrixSize
			matrix(i,j) = (1.0-m) * matrix(i,j)  
		END DO
	END DO
	
	temp = 1
	DO WHILE (ABS(temp -  ranking(1,1)) > threshold)
		temp = ranking(1,1)
		matrix = matmul(matrix, matrix)
	    ranking = matmul(matrix, S)
	END DO

	DO i=1, matrixSize
		PRINT *, ranking(i, 1)
	END DO
	
	DEALLOCATE(S)
	DEALLOCATE(ranking)
END SUBROUTINE