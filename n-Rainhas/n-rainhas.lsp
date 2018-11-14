(defun queens (n &optional (m n))
  (if (zerop n) ;booleano para descobrir se o número de rainhas é diferente de 0
      (list nil) 
      (loop for solucao in (queens (1- n) m)
            nconc (loop for new-col from 1 to m
                         when (loop for linha from 1 to n
                                     for col in solucao
                                     always (/= new-col col (+ col linha) (- col linha))) ;verifica ameaça na diagonal
                         collect (cons new-col solucao))))) 
