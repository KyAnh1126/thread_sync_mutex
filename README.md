# thread_sync_mutex

- repo mô tả vấn đề về đồng bộ hóa các luồng với hai ví dụ
- vì các luồng chia sẻ bộ nhớ chung của tiến trình, các luồng được lập lịch bởi kernel có thể tranh chấp tài nguyên chung nếu không cẩn thận
- cần mutex để đồng bộ hóa các luồng

1. thread_sync_problem1.cpp
- ví dụ 1 chỉ ra các luồng tranh chấp tài nguyên chung là biến counter (global variable)
- vòng for dùng để kernel thực hiện context-switch giữa các luồng (vì vòng lặp dài sẽ thực thi lâu)
- lúc này, khi luồng 1 chưa thực thi xong lệnh, thì luồng 2 được thực thi và sử dụng biến counter

2. thread_sync_problem2.cpp
- các luồng trong ví dụ này tranh chấp biến mails (global variable)
- vì khi biên dịch chương trình C, sẽ cần biên dịch các dòng lệnh của chương trình thành ngôn ngữ ASSEMBLY, các luồng xảy ra vấn đề bất đồng bộ
- kết quả của file không đưa ra chính xác giá trị của biến mails
