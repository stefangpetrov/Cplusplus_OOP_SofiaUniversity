# Практикум 03 - Мартеници
Целта на днешните задачи е да поработим с голямата четворка, както и да започнем да изграждаме интуиция, която да ни помага да превръщаме "нужди" в "код". Задачите са обяснени абстрактно точно с тази цел. Ако нещо не е изрично казано е ваша отговорност да изберете поведението на вашия клас в дадени моменти.


## Задача 01
Баба Марта решила да раздава мартеници на студентите от ФМИ, но хвърчащото листче, на което си била записала, на кой, каква мартеница да подари, е
изчезнало безследно. Обаче Марта навлиза бързо в новото време и технологиите, решила да възстанови списъка си, но този път да го запише във файл. На всеки ред от файла има следната информация:
- име на студента притежател на мартеницата
- пожелание от баба Марта
- дължина на мартеницата в сантиметри
- брой на мъниста по мартеницата

По обясними причини, добрата баба иска да зареди информацията в RAM паметта на машината си и моли умните студенти от ФМИ да напишат един клас
`Martenitsa`, който да съдържа цялата инфомация за една мартеница. За да тества системата, Марта иска да въведе инфомацията от конзолата, но за сега, само за една мартеница. После иска да види, дали информацията в конзолата е правилно записана. 

## Задача 02
Макар и най-важната задача на баба Марта да е раздаването на мартеници с цел здраве на целия народ, тази година баба Марта се е повлияла от всички млади предприемачи и е решила другата година да оптимизира продажбите си. 

Нейната цел е в края на празника да изведе статистика за най-продаван вид мартеница. За нея една мартеница се определя от дължината на самата мартеница и броят мъниста.

Баба Марта не се интересува нито от името на студентите, на които е подарила мартеници, нито от пожеланието, което е сложила. Макар че тази информация ще бъде там, нейната валидност не е важна, за нея има стойност само в дължината на мартеницата и броя мъниста. 

С цел да не се претоварва, баба Марта ще използва същия списък от предишната задача. За наш късмет тя си мисли, че текстовите файлове на компютъра могат да събират информация горе долу колкото един лист хартия, което е около 25 мартеници. Баба Марта казва, че никога не е имала повече от 10 листа, така че може да считате, че няма да бъдат въведени повече от 250 мартеници. 


Вашата задача е да напишете клас `MartenitsaContainer`(или име по ваш избор), който да може да съхранява до 250 мартеници и да изважда информация за най-продаваната/подаряваната мартеница. Баба Марта не иска в статистиката да бъдат включени невалидни мартеници, които имат нулева или отрицателно дължина, както и мартеници, които имат отрицателен брой мъниста.

**Бележка:** предефинирахме `operator=`, също знаем какво прави две мартеници еднакви за баба Марта, кой оператор можем да предефинираме, за да сравняваме мартеници? 

**Бонус:** Можете вместо да извеждате информация за най-добрата мартеница, да пробвате да изведете статистика за петте най-продавани мартеници, това ще включва сортировка на сложни обекти като `Martenitsa`. Кога една мартеница е "по-голяма" от друга? Бихме препоръчали да го пробвате вкъщи.

## Задача 03
След успешното изпълнение на 2 поръчки, баба Марта ви има пълно доверие. Амбициозната цел да стане по-богата, в комбинация с новооткритата сила на технологията в България започва да превзема съзнанието на баба Марта. Тя е решила, че иска да автоматизира бизнеса си. За да се различава от останалите баби Марти, нашата баба Марта иска да може нейните, макар и автоматично създадени, мартеници да имат персонален допир с клиента.

Вашата задача е да напишете специален клас `MartenitsaGenerator`, който да генерира мартеници. Баба Марта иска този клас да може следните неща:
- генерация на напълно случайна мартеница с всичките и полета рандомизирани.
- генерация на случайна мартеница, но с вече избрано име.
- генерация на случайна мартеница, но с вече избрано пожелание.
- генерация на случайна мартеница с вече избрано име и пожелание.
- генерация на много случайни мартеници.
- генерация на много случайни мартеници с вече избрано име.
- генерация на много случайни мартеници с вече избрано пожелание.
- генерация на много случайни мартеници с избрано име и пожелания.

Тъй като баба Марта е прогресивна, тя иска да се възползва от информацията, която е получила от втората си поръчка към вас. Изисква се вашият клас да може да се конфигурира още при създаването си -да е възможно да се избират дължината и броят мъниста на мартениците, които ще биват създавани. Ако някоя от двете стойности не е избрана да се използва случайна стойност между 10 и 30.

## Задача 3.5
Имате уникалната възможност да проверите силата на вашите продукти, използвайте `MartenitsaGenerator` и `MartenitsaContainer`, като генерирате случайни мартеници и извадите информация/статистика за тях.

## Задача 04
Бизнесът на баба Марта избухнал, вече е декември, а тя все още продава мартеници!

Втората поръчка, която показва статистиката на купените мартеници е много полезна, но вече не е достатъчна за баба Марта, тя иска да може да чете произволен брой мартеници от конзолата и да ги запазва.

Баба Марта иска да промените класа, който се грижи за статистиката на мартеници, така че да поддържа произволен брой мартеници.

Баба Марта също е осъзнала, че няма нужда да пази безполезна информация, тя иска да може да маха всички мартеници с дадена дължина и брой мъниста.

Също тъй като и без това статистиката не използва невалидни мартеници, баба Марта е решила, че може директно те да не се добавят, вместо просто да се игнорират при създаването на статистика.
