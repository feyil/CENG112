#ifndef GPSPATHLIST_H
#define GPSPATHLIST_H

class GPSPathList
{
 public:
  GPSPathList(){m_size=0;  m_item_list=0;};
  ~GPSPathList(){delete_items();};
  bool add_point(const double la, const double lo);
  double total_distance();
  void print();
 private:
  struct GPSCoordNode
  {
    double longtitude;
    double lattitude;
    GPSCoordNode* next;
  };
  void delete_items();
  GPSCoordNode* m_item_list;
  size_t m_size;
};

#endif
