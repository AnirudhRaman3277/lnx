#!/bin/bash 
 
INVENTORY_FILE="inventory.txt" 
SALES_LOG="sales_log.txt" 
 
if [ ! -f "$INVENTORY_FILE" ]; then 
echo "ProductID,ProductName,Quantity,Price" > "$INVENTORY_FILE" 
fi 
 
if [ ! -f "$SALES_LOG" ]; then 
echo "SaleID,ProductID,ProductName,Quantity,TotalPrice,Date" > "$SALES_LOG" 
fi 
 
add_product() { 
echo "Enter Product ID:" 
    read product_id 
    echo "Enter Product Name:" 
    read product_name 
    echo "Enter Quantity:" 
read quantity 
  echo "Enter Price (per unit):" 
  read price 
echo "$product_id,$product_name,$quantity,$price" >> "$INVENTORY_FILE" 
echo "Product added successfully!" 
echo "" 
} 
 
view_inventory() { 
echo "" 
    cat "$INVENTORY_FILE" | tail -n +2 
    echo "" 
} 
 
generate_bill() { 
    echo "Enter Product ID:" 
    read product_id 
    echo "Enter Quantity:" 
    read quantity 
    product_details=$(grep "^$product_id," "$INVENTORY_FILE") 
 
    if [ -z "$product_details" ]; then 
        echo "Product not found!" 
        return 
    fi 
 
    product_name=$(echo "$product_details" | cut -d',' -f2) 
    available_quantity=$(echo "$product_details" | cut -d',' -f3) 
    price=$(echo "$product_details" | cut -d',' -f4) 
 
    if [ "$quantity" -gt "$available_quantity" ]; then 
        echo "Insufficient stock!" 
        return 
    fi 
 
    total_price=$(echo "$price * $quantity" | bc) 
    new_quantity=$((available_quantity - quantity)) 
    sed -i "s/^$product_id,.*/$product_id,$product_name,$new_quantity,$price/" 
"$INVENTORY_FILE" 
 
    sale_id=$(date +%Y%m%d%H%M%S) 
    sale_date=$(date +"%Y-%m-%d %H:%M:%S") 
    echo "$sale_id,$product_id,$product_name,$quantity,$total_price,$sale_date" >> 
"$SALES_LOG" 
    
    echo "" 
    echo "---------- Bill ----------" 
    echo "Product: $product_name" 
    echo "Quantity: $quantity" 
    echo "Total Price: $total_price" 
    echo "Date: $sale_date" 
    echo "--------------------------" 
    echo "" 
} 
 
view_sales_log() { 
    echo "" 
    cat "$SALES_LOG" | tail -n +2 
    echo "" 
} 
 
while true; 
do 
    echo "1. Add Product to Inventory" 
    echo "2. View Inventory" 
    echo "3. Generate Bill" 
    echo "4. View Sales Log" 
    echo "5. Exit" 
    echo "Choose an option:" 
    read choice 
 
    case $choice in 
        1) add_product ;; 
        2) view_inventory ;; 
        3) generate_bill ;; 
        4) view_sales_log ;; 
        5) echo "Goodbye!"; exit 0 ;; 
        *) echo "Invalid option, try again." ;; 
    esac 
done