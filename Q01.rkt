#lang racket

; Multiples of 3 and 5
; Problem 1
; 
; If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
; The sum of these multiples is 23.
; Find the sum of all the multiples of 3 or 5 below 1000.
;
; https://projecteuler.net/problem=1

; Recursive Solution
(define problem-1-rec
  (lambda ([start 1] [sum 0])
    (cond
      [(< start 1000)
       (cond
        [(or (= (modulo start 3) 0) (= (modulo start 5) 0)) (problem-1-rec (+ start 1) (+ sum start))]
        [else (problem-1-rec (+ start 1) sum)]
        )]
      [else sum]
      )
    )
)

; Using range and foldl 
(define problem-1-fold
  (lambda ()
    (foldl
     (lambda (num sum) (if (or (= (modulo num 3) 0) (= (modulo num 5) 0)) (+ num sum) sum))
     0 (range 1 1000)
     )
    )
)

; Using range, filter, and apply
(define problem-1-oneliner
  (lambda ()
    (apply + (filter (lambda (num) (or (= (modulo num 3) 0) (= (modulo num 5) 0))) (range 1 1000)))
    )
)

; (problem-1-rec)
; (problem-1-fold)
; (problem-1-oneliner)

