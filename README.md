Описание
Реализация бинарного дерева и алгоритма вертикального обхода этого дерева.

Класс Node
Класс Node представляет узел бинарного дерева. У каждого узла есть значение value, и ссылки на потомков left и right.

Функция Tree
Функция Tree принимает вектор строк values и строит бинарное дерево из этих значений. Значения должны быть представлены в формате уровневого обхода (level-order traversal), где каждый узел представлен его значением, а отсутствующие узлы обозначаются как null. Функция возвращает корень построенного дерева.

Функция vertTraversal
Функция vertTraversal выполняет вертикальный обход бинарного дерева. Она принимает корень дерева и возвращает вектор векторов, где каждый внутренний вектор содержит все значения узлов в одной вертикальной линии.

Алгоритм
Алгоритм вертикального обхода работает следующим образом:

Создается map columns, где ключи - это номера колонок, а значения - это векторы значений узлов в этих колонках.
Создается очередь q, которая будет хранить пары из узлов и их колонок.
Корневой узел добавляется в очередь с колонкой 0.
Пока очередь не пуста, извлекается узел и его колонка. Значение узла добавляется в соответствующую колонку в карте. Если у узла есть левый или правый потомок, они добавляются в очередь с колонками, уменьшенными или увеличенными на 1 соответственно.
В конце алгоритма векторы значений из карты columns добавляются в результирующий вектор.
Сложность
Сложность обоих функций Tree и vertTraversal равна O(n), где n - количество узлов в дереве, т.к. каждый узел посещается ровно один раз.
