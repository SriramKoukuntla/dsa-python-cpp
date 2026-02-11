class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if (a.score != b.score) return (a.score > b.score) ? 1 : -1;
        if (a.name != b.name) return (a.name < b.name) ? 1 : -1;
        return 0;
    }
};