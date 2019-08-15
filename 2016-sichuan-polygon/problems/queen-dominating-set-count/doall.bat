rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 1" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 2" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 3" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 4" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 5" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 6" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 7" "tests\11" 11
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 8" "tests\12" 12
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 9" "tests\13" 13
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 10" "tests\14" 14
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 11" "tests\15" 15
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 12" "tests\16" 16
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 13" "tests\17" 17
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 14" "tests\18" 18
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 15" "tests\19" 19
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 16" "tests\20" 20
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 17" "tests\21" 21
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 18" "tests\22" 22
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 19" "tests\23" 23
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 20" "tests\24" 24
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 21" "tests\25" 25
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 22" "tests\26" 26
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 23" "tests\27" 27
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 24" "tests\28" 28
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 25" "tests\29" 29
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 26" "tests\30" 30
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 27" "tests\31" 31
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 28" "tests\32" 32
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 29" "tests\33" 33
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 30" "tests\34" 34
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 31" "tests\35" 35
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 32" "tests\36" 36
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 33" "tests\37" 37
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 34" "tests\38" 38
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 35" "tests\39" 39
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 36" "tests\40" 40
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 37" "tests\41" 41
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 38" "tests\42" 42
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 39" "tests\43" 43
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 40" "tests\44" 44
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 41" "tests\45" 45
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 42" "tests\46" 46
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 43" "tests\47" 47
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 44" "tests\48" 48
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 45" "tests\49" 49
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 46" "tests\50" 50
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 47" "tests\51" 51
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 48" "tests\52" 52
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 49" "tests\53" 53
call scripts\gen-input-via-stdout.bat "files\random.exe 50 8 50" "tests\54" 54
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 1" "tests\55" 55
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 2" "tests\56" 56
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 3" "tests\57" 57
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 4" "tests\58" 58
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 5" "tests\59" 59
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 6" "tests\60" 60
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 7" "tests\61" 61
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 8" "tests\62" 62
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 9" "tests\63" 63
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 10" "tests\64" 64
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 11" "tests\65" 65
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 12" "tests\66" 66
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 13" "tests\67" 67
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 14" "tests\68" 68
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 15" "tests\69" 69
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 16" "tests\70" 70
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 17" "tests\71" 71
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 18" "tests\72" 72
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 19" "tests\73" 73
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000 8 20" "tests\74" 74
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 1" "tests\75" 75
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 2" "tests\76" 76
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 3" "tests\77" 77
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 4" "tests\78" 78
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 5" "tests\79" 79
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 6" "tests\80" 80
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 7" "tests\81" 81
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 8" "tests\82" 82
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 9" "tests\83" 83
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 10" "tests\84" 84
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 11" "tests\85" 85
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 12" "tests\86" 86
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 13" "tests\87" 87
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 14" "tests\88" 88
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 15" "tests\89" 89
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 16" "tests\90" 90
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 17" "tests\91" 91
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 18" "tests\92" 92
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 19" "tests\93" 93
call scripts\gen-input-via-stdout.bat "files\random.exe 1000000000 8 20" "tests\94" 94
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""
call scripts\gen-answer.bat tests\12 tests\12.a "tests" ""
call scripts\gen-answer.bat tests\13 tests\13.a "tests" ""
call scripts\gen-answer.bat tests\14 tests\14.a "tests" ""
call scripts\gen-answer.bat tests\15 tests\15.a "tests" ""
call scripts\gen-answer.bat tests\16 tests\16.a "tests" ""
call scripts\gen-answer.bat tests\17 tests\17.a "tests" ""
call scripts\gen-answer.bat tests\18 tests\18.a "tests" ""
call scripts\gen-answer.bat tests\19 tests\19.a "tests" ""
call scripts\gen-answer.bat tests\20 tests\20.a "tests" ""
call scripts\gen-answer.bat tests\21 tests\21.a "tests" ""
call scripts\gen-answer.bat tests\22 tests\22.a "tests" ""
call scripts\gen-answer.bat tests\23 tests\23.a "tests" ""
call scripts\gen-answer.bat tests\24 tests\24.a "tests" ""
call scripts\gen-answer.bat tests\25 tests\25.a "tests" ""
call scripts\gen-answer.bat tests\26 tests\26.a "tests" ""
call scripts\gen-answer.bat tests\27 tests\27.a "tests" ""
call scripts\gen-answer.bat tests\28 tests\28.a "tests" ""
call scripts\gen-answer.bat tests\29 tests\29.a "tests" ""
call scripts\gen-answer.bat tests\30 tests\30.a "tests" ""
call scripts\gen-answer.bat tests\31 tests\31.a "tests" ""
call scripts\gen-answer.bat tests\32 tests\32.a "tests" ""
call scripts\gen-answer.bat tests\33 tests\33.a "tests" ""
call scripts\gen-answer.bat tests\34 tests\34.a "tests" ""
call scripts\gen-answer.bat tests\35 tests\35.a "tests" ""
call scripts\gen-answer.bat tests\36 tests\36.a "tests" ""
call scripts\gen-answer.bat tests\37 tests\37.a "tests" ""
call scripts\gen-answer.bat tests\38 tests\38.a "tests" ""
call scripts\gen-answer.bat tests\39 tests\39.a "tests" ""
call scripts\gen-answer.bat tests\40 tests\40.a "tests" ""
call scripts\gen-answer.bat tests\41 tests\41.a "tests" ""
call scripts\gen-answer.bat tests\42 tests\42.a "tests" ""
call scripts\gen-answer.bat tests\43 tests\43.a "tests" ""
call scripts\gen-answer.bat tests\44 tests\44.a "tests" ""
call scripts\gen-answer.bat tests\45 tests\45.a "tests" ""
call scripts\gen-answer.bat tests\46 tests\46.a "tests" ""
call scripts\gen-answer.bat tests\47 tests\47.a "tests" ""
call scripts\gen-answer.bat tests\48 tests\48.a "tests" ""
call scripts\gen-answer.bat tests\49 tests\49.a "tests" ""
call scripts\gen-answer.bat tests\50 tests\50.a "tests" ""
call scripts\gen-answer.bat tests\51 tests\51.a "tests" ""
call scripts\gen-answer.bat tests\52 tests\52.a "tests" ""
call scripts\gen-answer.bat tests\53 tests\53.a "tests" ""
call scripts\gen-answer.bat tests\54 tests\54.a "tests" ""
call scripts\gen-answer.bat tests\55 tests\55.a "tests" ""
call scripts\gen-answer.bat tests\56 tests\56.a "tests" ""
call scripts\gen-answer.bat tests\57 tests\57.a "tests" ""
call scripts\gen-answer.bat tests\58 tests\58.a "tests" ""
call scripts\gen-answer.bat tests\59 tests\59.a "tests" ""
call scripts\gen-answer.bat tests\60 tests\60.a "tests" ""
call scripts\gen-answer.bat tests\61 tests\61.a "tests" ""
call scripts\gen-answer.bat tests\62 tests\62.a "tests" ""
call scripts\gen-answer.bat tests\63 tests\63.a "tests" ""
call scripts\gen-answer.bat tests\64 tests\64.a "tests" ""
call scripts\gen-answer.bat tests\65 tests\65.a "tests" ""
call scripts\gen-answer.bat tests\66 tests\66.a "tests" ""
call scripts\gen-answer.bat tests\67 tests\67.a "tests" ""
call scripts\gen-answer.bat tests\68 tests\68.a "tests" ""
call scripts\gen-answer.bat tests\69 tests\69.a "tests" ""
call scripts\gen-answer.bat tests\70 tests\70.a "tests" ""
call scripts\gen-answer.bat tests\71 tests\71.a "tests" ""
call scripts\gen-answer.bat tests\72 tests\72.a "tests" ""
call scripts\gen-answer.bat tests\73 tests\73.a "tests" ""
call scripts\gen-answer.bat tests\74 tests\74.a "tests" ""
call scripts\gen-answer.bat tests\75 tests\75.a "tests" ""
call scripts\gen-answer.bat tests\76 tests\76.a "tests" ""
call scripts\gen-answer.bat tests\77 tests\77.a "tests" ""
call scripts\gen-answer.bat tests\78 tests\78.a "tests" ""
call scripts\gen-answer.bat tests\79 tests\79.a "tests" ""
call scripts\gen-answer.bat tests\80 tests\80.a "tests" ""
call scripts\gen-answer.bat tests\81 tests\81.a "tests" ""
call scripts\gen-answer.bat tests\82 tests\82.a "tests" ""
call scripts\gen-answer.bat tests\83 tests\83.a "tests" ""
call scripts\gen-answer.bat tests\84 tests\84.a "tests" ""
call scripts\gen-answer.bat tests\85 tests\85.a "tests" ""
call scripts\gen-answer.bat tests\86 tests\86.a "tests" ""
call scripts\gen-answer.bat tests\87 tests\87.a "tests" ""
call scripts\gen-answer.bat tests\88 tests\88.a "tests" ""
call scripts\gen-answer.bat tests\89 tests\89.a "tests" ""
call scripts\gen-answer.bat tests\90 tests\90.a "tests" ""
call scripts\gen-answer.bat tests\91 tests\91.a "tests" ""
call scripts\gen-answer.bat tests\92 tests\92.a "tests" ""
call scripts\gen-answer.bat tests\93 tests\93.a "tests" ""
call scripts\gen-answer.bat tests\94 tests\94.a "tests" ""

