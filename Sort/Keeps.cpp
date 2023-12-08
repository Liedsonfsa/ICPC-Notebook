//O stable_sort, faz comparação e caso não atenda a comparação mantem a ordem original
stable_sort(all(v), [](string a, string b) {
      return (a.size() != b.size()) ? a.size() > b.size() : false;
});
