#!/bin/bash

# Set the source branch and destination base directory
SOURCE_BRANCH="jisoo"
DESTINATION_PLACE_1="math"
DESTINATION_PLACE_2="object"

# List of files what you want to copy from the source branch
FILES_1=(

)

FILES_2=(

)

# Print out the Current branch name make sure the files will be copied to the right place
CURRENT_BRANCH=$(git rev-parse --abrev-ref HEAD)
echo "Copying files from '$SOURCE_BRANCH' to '$CURRENT_BRANCH' in 
	'$DESTINATION_PLACE_1', '$DESTINATION_PLACE_2'..."

mkdir -p "$DESTINATION_PLACE_1"
mkdir -p "$DESTINATION_PLACE_2"

for FILE_1 in "${FILES_1[@]}"; do
	echo "Checking out $FILE_1 from $SOURCE_BRANCH..."
	git checkout "$SOURCE_BRANCH" -- "$FILE_1" || {
		echo "Failed to checckout $FILE_1"
		continue
	}

	DESTINATION_PATH_1="$DESTINATION_PLACE_1/$(basename "$FILE")"
	echo "Moving $FILE to $DESTINATION_PATH_1..."
	mkdir -p "$(dirname "$DESTINATION_PATH_1")"
	mv "$FILE" "$DESTINATION_PATH_1"

done

for FILE_2 in "${FILES_2[@]}"; do
	echo "Checking out $FILE_2 from $SOURCE_BRANCH..."
	git checkout "$SOURCE_BRANCH" -- "$FILE_2" || {
		echo "Failed to checckout $FILE_2"
		continue
	}

	DESTINATION_PATH_2="$DESTINATION_PLACE_2/$(basename "$FILE")"
	echo "Moving $FILE to $DESTINATION_PATH_2..."
	mkdir -p "$(dirname "$DESTINATION_PATH_2")"
	mv "$FILE" "$DESTINATION_PATH_2"

done

echo "All files copied. You can now stage and commit the changes:"
echo " git add $DESTINATION_PLACE_1 $DESTINATION_PLACE_2 && git commit -m 
	'The $FILE_1, $FILE_2 Copied files from $SOURCE_BRANCH'"
