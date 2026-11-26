import java.util.*;

class NumberContainers {
    HashMap<Integer, Integer> map = new HashMap<>();
    HashMap<Integer, PriorityQueue<Integer>> pq = new HashMap<>();

    public NumberContainers() {
    }

    public void change(int index, int number) {
        map.put(index, number);
        pq.putIfAbsent(number, new PriorityQueue<>());
        pq.get(number).add(index);
    }

    public int find(int number) {
        if (!pq.containsKey(number))
            return -1;

        while (!pq.get(number).isEmpty() &&
               !Objects.equals(map.get(pq.get(number).peek()), number)) {
            pq.get(number).poll();
        }

        return pq.get(number).isEmpty() ? -1 : pq.get(number).peek();
    }
}