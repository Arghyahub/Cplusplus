
#!/bin/bash
filename="temp.txt"

# Check if file exists
if [ ! -f "$filename" ]; then
    echo "File '$filename' not found."
    exit 1
fi

# Print the first line
first_line=$(head -n 1 "$filename")
echo "First Line: $first_line"

# Delete the first line and save the changes
sed -i '1d' "$filename"

code $first_line 
