SUBROUTINE get_ranking(matrix)
	INTEGER :: matrixSize, i, j, current
	INTEGER :: matrixShape(2)
	DOUBLE PRECISION :: threshold, m, greater
	DOUBLE PRECISION, DIMENSION(:,:) :: matrix
	DOUBLE PRECISION, DIMENSION(:,:), ALLOCATABLE :: S, ranking, ltemp
	
	threshold = 1E-5
	m = 0.15

	matrixShape = SHAPE(matrix)
	IF (matrixShape(1) /= matrixShape(2)) THEN
		PRINT *, "ERRO: Matriz de entrada não é quadrada"
		STOP 1
	END IF 

	matrixSize = matrixShape(1)
	ALLOCATE(S(matrixSize, 1))
	ALLOCATE(ranking(matrixSize, 1))
	ALLOCATE(ltemp(matrixSize, 1))
	
	DO i = 1, matrixSize
		DO j = 1, matrixSize
			matrix(i,j) = (1.0-m) * matrix(i,j)  
		END DO
	END DO

	DO i = 1, matrixSize
		S(i,1) = m * (1.0 / matrixSize)
		ranking(i,1) = 1
	END DO

	DO WHILE (ABS(ltemp(1,1) - ranking(1,1)) > threshold)
		ltemp = ranking
	    ranking = matmul(matrix, ltemp)

		DO i = 1, matrixSize
			ranking(i, 1) = ranking(i, 1) + S(i, 1)
		END DO
	END DO

	PRINT *, "   Iteracao", " |", "      Pagina", " |", "  Peso"
	DO i = 1, matrixSize
		greater = 0
		current = 0
		DO j = 1, matrixSize
			IF (ranking(j, 1) > 0 .AND. ranking(j, 1) > greater) THEN
				greater = ranking(j, 1)
				current = j
			END IF
		END DO

		ranking(current, 1) = -1
		PRINT *, i, "|", current, "|", greater
	END DO
	
	DEALLOCATE(S)
	DEALLOCATE(ranking)
	DEALLOCATE(ltemp)
END SUBROUTINE