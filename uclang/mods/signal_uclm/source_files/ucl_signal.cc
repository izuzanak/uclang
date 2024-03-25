
@begin
include "ucl_signal.h"
@end

/*
 * methods of generated structures
 */

// -- search_result_s --
@begin
methods search_result_s
@end

// -- search_results_s --
@begin
methods search_results_s
@end

/*
 * methods of structure data_signal_s
 */

void data_signal_s::search_2d(bd_array_s *a_data[2],bd_array_s *a_win[2],
    unsigned a_step,unsigned a_dist,double a_dist_max,unsigned a_dist_count,
    search_results_s &a_results)
{/*{{{*/
  unsigned win_len = a_win[0]->used;
  unsigned data_len = a_data[0]->used;

  double *win0 = a_win[0]->data;
  double *win1 = a_win[1]->data;

  double *data0 = a_data[0]->data;
  double *data1 = a_data[1]->data;

  unsigned start = 0;
  do
  {
    double dist_sum = 0.0;
    unsigned dist_cnt = 0;

    unsigned di = start;
    unsigned di_end = data_len;

    unsigned wi = 0;
    unsigned wi_end = win_len;

    unsigned di_start = 0;

    do {

      // - search in data -
      double dmin_dist = INFINITY;
      unsigned dmin_idx = c_idx_not_exist;

      unsigned dii = di;
      unsigned dii_end = dii + a_dist;

      double w0 = win0[wi];
      double w1 = win1[wi];

      do
      {
        double d0 = 0.0;
        double d1 = 0.0;

        if (dii < di_end)
        {
          d0 = data0[dii];
          d1 = data1[dii];
        }

        double dist0 = d0 - w0;
        double dist1 = d1 - w1;
        double dist = dist0*dist0 + dist1*dist1;

        if (dist < dmin_dist)
        {
          dmin_dist = dist;
          dmin_idx = dii;
        }
      } while(++dii < dii_end);

      // - search in window -
      double wmin_dist = INFINITY;
      unsigned wmin_idx = c_idx_not_exist;

      unsigned wii = wi;
      unsigned wii_end = wii + a_dist;

      double d0 = data0[di];
      double d1 = data1[di];

      do
      {
        double w0 = 0.0;
        double w1 = 0.0;

        if (wii < wi_end)
        {
          w0 = win0[wii];
          w1 = win1[wii];
        }

        double dist0 = d0 - w0;
        double dist1 = d1 - w1;
        double dist = dist0*dist0 + dist1*dist1;

        if (dist < wmin_dist)
        {
          wmin_dist = dist;
          wmin_idx = wii;
        }
      } while(++wii < wii_end);

      if (wmin_dist < dmin_dist)
      {
        dist_sum += wmin_dist;
        wi = wmin_idx;
      }
      else
      {
        dist_sum += dmin_dist;
        di = dmin_idx;
      }

      if (dist_cnt == 0) { di_start = di; }

      ++di;
      ++wi;
      ++dist_cnt;

    } while(di < di_end && wi < wi_end);

    if (dist_cnt >= a_dist_count)
    {
      double dist = dist_sum/dist_cnt;

      // - apply distance of start position -
      {
        double dist0 = win0[0] - data0[di_start];
        double dist1 = win1[0] - data1[di_start];
        dist += sqrt(dist0*dist0 + dist1*dist1);
      }

      // - apply distance of end position -
      {
        double dist0 = win0[win_len - 1] - data0[di - 1];
        double dist1 = win1[win_len - 1] - data1[di - 1];
        dist += sqrt(dist0*dist0 + dist1*dist1);
      }

      if (dist <= a_dist_max)
      {
        unsigned res_start = di_start;
        unsigned res_end = di - 1;
        bool insert = false;

        do
        {
          if (a_results.used == 0)
          {
            insert = true;
            break;
          }

          search_result_s &last_res = a_results.last();

          if (res_start >= last_res.end)
          {
            insert = true;
            break;
          }

          if (dist < last_res.dist)
          {
            a_results.pop();
            insert = true;
            break;
          }
        } while(0);

        if (insert)
        {
          a_results.push_blank();
          a_results.last().set(res_start,res_end,dist,dist_cnt);
        }
      }
    }

    start += a_step;
  } while(start + win_len <= data_len);
}/*}}}*/

